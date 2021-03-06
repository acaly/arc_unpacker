#include "formats/nitroplus/pak_archive.h"
#include "test_support/archive_support.h"
#include "test_support/catch.hpp"
using namespace Formats::Nitroplus;

static void test_pak_archive(const std::string &path)
{
    std::shared_ptr<File> file1(new File);
    std::shared_ptr<File> file2(new File);
    file1->name = "abc.txt";
    file2->name = "another.txt";
    file1->io.write("123", 3);
    file2->io.write("abcdefghij", 10);
    std::vector<std::shared_ptr<File>> expected_files { file1, file2 };

    std::unique_ptr<Archive> archive(new PakArchive);
    compare_files(expected_files,  unpack_to_memory(path, *archive));
}

TEST_CASE("Unpacking uncompressed PAK archives works")
{
    test_pak_archive("tests/formats/nitroplus/files/uncompressed.pak");
}

TEST_CASE("Unpacking compressed PAK archives works")
{
    test_pak_archive("tests/formats/nitroplus/files/compressed.pak");
}
