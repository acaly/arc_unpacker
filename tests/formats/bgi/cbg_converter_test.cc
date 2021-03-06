#include "formats/bgi/cbg_converter.h"
#include "test_support/catch.hpp"
#include "test_support/converter_support.h"
using namespace Formats::Bgi;

static void test_cbg_decoding(
    const std::string &input_image_path,
    const std::string &expected_image_path)
{
    CbgConverter converter;
    assert_decoded_image(converter, input_image_path, expected_image_path);
}

TEST_CASE("Decoding 24-bit CBG images works")
{
    test_cbg_decoding(
        "tests/formats/bgi/files/3",
        "tests/formats/bgi/files/3-out.png");
}

TEST_CASE("Decoding 8-bit CBG images works")
{
    test_cbg_decoding(
        "tests/formats/bgi/files/4",
        "tests/formats/bgi/files/4-out.png");
}

TEST_CASE("Decoding 32-bit CBG images works")
{
    test_cbg_decoding(
        "tests/formats/bgi/files/ti_si_de_a1",
        "tests/formats/bgi/files/ti_si_de_a1-out.png");
}
