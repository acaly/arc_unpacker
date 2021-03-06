// TLG image
//
// Company:   -
// Engine:    Kirikiri
// Extension: .tlg
// Archives:  XP3
//
// Known Games:
// - Fate/Stay Night
// - Fate/Hollow Ataraxia

#include <stdexcept>
#include "formats/kirikiri/tlg/tlg5_decoder.h"
#include "formats/kirikiri/tlg/tlg6_decoder.h"
#include "formats/kirikiri/tlg_converter.h"
using namespace Formats::Kirikiri;
using namespace Formats::Kirikiri::Tlg;

namespace
{
    const std::string magic_tlg_0("TLG0.0\x00sds\x1a", 11);
    const std::string magic_tlg_5("TLG5.0\x00raw\x1a", 11);
    const std::string magic_tlg_6("TLG6.0\x00raw\x1a", 11);

    int guess_version(IO &io);
    std::unique_ptr<File> decode_proxy(int version, File &file);

    std::string extract_string(std::string &container)
    {
        size_t length = 0;
        while (container.length() && container[0] >= '0' && container[0] <= '9')
        {
            length *= 10;
            length += container[0] - '0';
            container.erase(0, 1);
        }
        container.erase(0, 1);
        std::string str = container.substr(0, length);
        container.erase(0, length + 1);
        return str;
    }

    std::unique_ptr<File> decode_tlg_0(File &file)
    {
        size_t raw_data_size = file.io.read_u32_le();
        size_t raw_data_offset = file.io.tell();

        std::vector<std::pair<std::string, std::string>> tags;

        file.io.skip(raw_data_size);
        while (file.io.tell() < file.io.size())
        {
            std::string chunk_name = file.io.read(4);
            size_t chunk_size = file.io.read_u32_le();
            std::string chunk_data = file.io.read(chunk_size);

            if (chunk_name == "tags")
            {
                while (chunk_data != "")
                {
                    std::string key = extract_string(chunk_data);
                    std::string value = extract_string(chunk_data);
                    tags.push_back(
                        std::pair<std::string, std::string>(key, value));
                }
            }
            else
                throw std::runtime_error("Unknown chunk: " + chunk_name);
        }

        file.io.seek(raw_data_offset);
        int version = guess_version(file.io);
        if (version == -1)
            throw std::runtime_error("Unknown TLG version");
        return decode_proxy(version, file);
    }

    std::unique_ptr<File> decode_tlg_5(File &file)
    {
        Tlg5Decoder decoder;
        return decoder.decode(file);
    }

    std::unique_ptr<File> decode_tlg_6(File &file)
    {
        Tlg6Decoder decoder;
        return decoder.decode(file);
    }

    int guess_version(IO &io)
    {
        size_t pos = io.tell();
        if (io.read(magic_tlg_0.size()) == magic_tlg_0)
            return 0;

        io.seek(pos);
        if (io.read(magic_tlg_5.size()) == magic_tlg_5)
            return 5;

        io.seek(pos);
        if (io.read(magic_tlg_6.size()) == magic_tlg_6)
            return 6;

        return -1;
    }

    std::unique_ptr<File> decode_proxy(int version, File &file)
    {
        switch (version)
        {
            case 0:
                return decode_tlg_0(file);

            case 5:
                return decode_tlg_5(file);

            case 6:
                return decode_tlg_6(file);
        }
        throw std::runtime_error("Unknown TLG version");
    }
}

bool TlgConverter::is_recognized_internal(File &file) const
{
    return guess_version(file.io) >= 0;
}

std::unique_ptr<File> TlgConverter::decode_internal(File &file) const
{
    int version = guess_version(file.io);
    return decode_proxy(version, file);
}
