// P archive
//
// Company:   French Bread
// Engine:    -
// Extension: .p
//
// Known games:
// - Melty Blood

#include "formats/french_bread/ex3_converter.h"
#include "formats/french_bread/p_archive.h"
using namespace Formats::FrenchBread;

namespace
{
    const uint32_t encryption_key = 0xE3DF59AC;

    typedef struct
    {
        std::string name;
        size_t offset;
        size_t size;
    } TableEntry;

    typedef std::vector<std::unique_ptr<TableEntry>> Table;

    std::string read_file_name(IO &arc_io, size_t file_id)
    {
        std::string file_name = arc_io.read(60);
        for (size_t i = 0; i < 60; i ++)
            file_name[i] ^= file_id * i * 3 + 0x3d;
        return file_name.substr(0, file_name.find('\0'));
    }

    Table read_table(IO &arc_io)
    {
        size_t file_count = arc_io.read_u32_le() ^ encryption_key;
        Table table;
        for (size_t i = 0; i < file_count; i ++)
        {
            std::unique_ptr<TableEntry> table_entry(new TableEntry);
            table_entry->name = read_file_name(arc_io, i);
            table_entry->offset = arc_io.read_u32_le();
            table_entry->size = arc_io.read_u32_le() ^ encryption_key;
            table.push_back(std::move(table_entry));
        }
        return table;
    }

    std::unique_ptr<File> read_file(
        IO &arc_io, TableEntry &table_entry, bool encrypted)
    {
        std::unique_ptr<File> file(new File);
        std::unique_ptr<char[]> data(new char[table_entry.size]);
        char *ptr = data.get();
        arc_io.seek(table_entry.offset);
        arc_io.read(ptr, table_entry.size);

        for (size_t i = 0; i <= 0x2172 && i < table_entry.size; i ++)
            data[i] ^= table_entry.name[i % table_entry.name.size()] + i + 3;

        file->name = table_entry.name;
        file->io.write(ptr, table_entry.size);

        return file;
    }
}

struct PArchive::Internals
{
    Ex3Converter ex3_converter;
};


PArchive::PArchive() : internals(new Internals)
{
    add_transformer(&internals->ex3_converter);
}

PArchive::~PArchive()
{
}

bool PArchive::is_recognized_internal(File &arc_file) const
{
    uint32_t encrypted = arc_file.io.read_u32_le();
    size_t file_count = arc_file.io.read_u32_le() ^ encryption_key;
    if (encrypted != 0 && encrypted != 1)
        return false;
    if (file_count > arc_file.io.size() || file_count * 68 > arc_file.io.size())
        return false;
    for (size_t i = 0; i < file_count; i ++)
    {
        read_file_name(arc_file.io, i);
        size_t offset = arc_file.io.read_u32_le();
        size_t size = arc_file.io.read_u32_le() ^ encryption_key;
        if (offset + size > arc_file.io.size())
            return false;
    }
    return true;
}

void PArchive::unpack_internal(File &arc_file, FileSaver &file_saver) const
{
    bool encrypted = arc_file.io.read_u32_le() == 1;
    Table table = read_table(arc_file.io);
    for (auto &table_entry : table)
        file_saver.save(read_file(arc_file.io, *table_entry, encrypted));
}
