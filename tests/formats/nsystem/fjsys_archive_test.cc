#include "formats/nsystem/fjsys_archive.h"
#include "test_support/archive_support.h"
#include "test_support/catch.hpp"
using namespace Formats::NSystem;

TEST_CASE("Unpacking FJSYS archives works")
{
    std::shared_ptr<File> file1(new File);
    std::shared_ptr<File> file2(new File);
    file1->name = "abc.txt";
    file2->name = "another.txt";
    file1->io.write("123", 3);
    file2->io.write("abcdefghij", 10);
    std::vector<std::shared_ptr<File>> expected_files { file1, file2 };

    std::unique_ptr<Archive> archive(new FjsysArchive);
    compare_files(
        expected_files,
        unpack_to_memory("tests/formats/nsystem/files/test.fjsys", *archive));
}
