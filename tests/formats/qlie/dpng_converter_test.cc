#include "formats/qlie/dpng_converter.h"
#include "test_support/catch.hpp"
#include "test_support/converter_support.h"
using namespace Formats::QLiE;

TEST_CASE("Decoding DPNG images works")
{
    DpngConverter converter;
    assert_decoded_image(
        converter,
        "tests/formats/qlie/files/雷02.png",
        "tests/formats/qlie/files/雷02-out.png");
}
