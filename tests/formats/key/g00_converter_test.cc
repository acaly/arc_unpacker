#include "formats/key/g00_converter.h"
#include "test_support/catch.hpp"
#include "test_support/converter_support.h"
using namespace Formats::Key;

static void test_g00_decoding(
    const std::string &input_image_path,
    const std::string &expected_image_path)
{
    G00Converter converter;
    assert_decoded_image(converter, input_image_path, expected_image_path);
}

TEST_CASE("Decoding version 0 G00 images works")
{
    test_g00_decoding(
        "tests/formats/key/files/ayu_02.g00",
        "tests/formats/key/files/ayu_02-out.png");
}

TEST_CASE("Decoding version 1 G00 images works")
{
    test_g00_decoding(
        "tests/formats/key/files/ayu_05.g00",
        "tests/formats/key/files/ayu_05-out.png");
}

TEST_CASE("Decoding version 2 G00 images works")
{
    test_g00_decoding(
        "tests/formats/key/files/AYU_03.g00",
        "tests/formats/key/files/AYU_03-out.png");
}
