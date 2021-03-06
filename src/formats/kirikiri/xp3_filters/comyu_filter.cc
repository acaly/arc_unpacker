#include <memory>
#include "formats/kirikiri/xp3_filters/comyu_filter.h"
#include "formats/kirikiri/xp3_filters/cxdec_filter.h"
using namespace Formats::Kirikiri::Xp3Filters;

void ComyuFilter::decode(File &file, uint32_t key) const
{
    CxdecFilterSettings settings;
    settings.key1 = 0x1a3;
    settings.key2 = 0x0b6;

    settings.key_derivation_order1[0] = 0;
    settings.key_derivation_order1[1] = 1;
    settings.key_derivation_order1[2] = 2;

    settings.key_derivation_order2[0] = 0;
    settings.key_derivation_order2[1] = 7;
    settings.key_derivation_order2[2] = 5;
    settings.key_derivation_order2[3] = 6;
    settings.key_derivation_order2[4] = 3;
    settings.key_derivation_order2[5] = 1;
    settings.key_derivation_order2[6] = 4;
    settings.key_derivation_order2[7] = 2;

    settings.key_derivation_order3[0] = 4;
    settings.key_derivation_order3[1] = 3;
    settings.key_derivation_order3[2] = 2;
    settings.key_derivation_order3[3] = 1;
    settings.key_derivation_order3[4] = 5;
    settings.key_derivation_order3[5] = 0;

    settings.encryption_block =
        "\x20\x45\x6E\x63\x72\x79\x70\x74\x69\x6F\x6E\x20\x63\x6F\x6E\x74"
        "\x72\x6F\x6C\x20\x62\x6C\x6F\x63\x6B\x20\x2D\x2D\x20\x53\x74\x61"
        "\x74\x69\x63\x61\x6C\x6C\x79\x20\x6F\x72\x20\x64\x79\x6E\x61\x6D"
        "\x69\x63\x61\x6C\x6C\x79\x2C\x20\x64\x69\x72\x65\x63\x74\x6C\x79"
        "\x20\x6F\x72\x20\x69\x6E\x64\x69\x72\x65\x63\x74\x6C\x79\x2C\x20"
        "\x75\x73\x69\x6E\x67\x20\x74\x68\x69\x73\x20\x70\x72\x6F\x67\x72"
        "\x61\x6D\x20\x61\x6E\x64\x2F\x6F\x72\x20\x62\x6C\x6F\x63\x6B\x20"
        "\x66\x72\x6F\x6D\x20\x6F\x74\x68\x65\x72\x20\x70\x72\x6F\x67\x72"
        "\x61\x6D\x73\x20\x77\x69\x6C\x6C\x20\x62\x65\x20\x69\x6C\x6C\x65"
        "\x67\x61\x6C\x20\x62\x79\x20\x74\x68\x65\x20\x6C\x69\x63\x65\x6E"
        "\x73\x65\x20\x61\x67\x72\x65\x65\x6D\x65\x6E\x74\x2E\x20\x82\xB1"
        "\x82\xCC\x83\x76\x83\x8D\x83\x4F\x83\x89\x83\x80\x82\xE2\x83\x75"
        "\x83\x8D\x83\x62\x83\x4E\x82\xF0\x81\x41\x90\xC3\x93\x49\x82\xC5"
        "\x82\xA0\x82\xEA\x93\xAE\x93\x49\x82\xC5\x82\xA0\x82\xEA\x81\x41"
        "\x92\xBC\x90\xDA\x93\x49\x82\xC5\x82\xA0\x82\xEA\x8A\xD4\x90\xDA"
        "\x93\x49\x82\xC5\x82\xA0\x82\xEA\x81\x41\x91\xBC\x82\xCC\x83\x76"
        "\x83\x8D\x83\x4F\x83\x89\x83\x80\x82\xA9\x82\xE7\x97\x70\x82\xA2"
        "\x82\xE9\x82\xB1\x82\xC6\x82\xCD\x83\x89\x83\x43\x83\x5A\x83\x93"
        "\x83\x58\x82\xC9\x82\xE6\x82\xE8\x8B\xD6\x82\xB6\x82\xE7\x82\xEA"
        "\x82\xC4\x82\xA2\x82\xDC\x82\xB7\x81\x42\x0A\x43\x6F\x70\x79\x72"
        "\x69\x67\x68\x74\x28\x43\x29\x20\x32\x30\x30\x39\x20\x8B\xC5\x57"
        "\x4F\x52\x4B\x53\x2E\x20\x41\x6C\x6C\x20\x72\x69\x67\x68\x74\x73"
        "\x20\x72\x65\x73\x65\x72\x76\x65\x64\x2E\x0A\x0A\x81\x75\x89\xB4"
        "\x82\xBD\x82\xBF\x82\xCD\x83\x60\x81\x5B\x83\x80\x82\xBE\x81\x42"
        "\x0A\x81\x40\x82\xBD\x82\xC6\x82\xA6\x96\xA8\x8C\x8E\x82\xC9\x82"
        "\xCD\x93\xCD\x82\xA9\x82\xC8\x82\xA2\x8A\xD4\x95\xBF\x82\xC5\x82"
        "\xE0\x81\x42\x0A\x81\x40\x97\x98\x8A\x51\x82\xCC\x88\xEA\x92\x76"
        "\x82\xC5\x8C\x8B\x82\xD1\x82\xC2\x82\xAD\x81\x42\x0A\x81\x40\x89"
        "\x5E\x96\xBD\x8B\xA4\x93\xAF\x91\xCC\x82\xC8\x82\xE7\x82\xCA\x90"
        "\xB6\x91\xB6\x8B\xA4\x93\xAF\x91\xCC\x81\x5C\x81\x5C\x81\x5C\x81"
        "\x76\x0A\x0A\x8D\x82\x91\x71\x8E\x73\x90\x56\x93\x73\x90\x53\x81"
        "\x42\x0A\x8C\x96\x91\x9B\x82\xC6\x83\x6C\x83\x49\x83\x93\x82\xCC"
        "\x9A\xAE\x9A\xC4\x82\xC5\x82\xA0\x82\xE9\x96\xE9\x82\xCC\x8A\x58"
        "\x82\xC9\x81\x41\x88\xEA\x82\xC2\x82\xCC\x93\x60\x90\xE0\x82\xAA"
        "\x82\xA0\x82\xC1\x82\xBD\x81\x42\x0A\x0A\x82\xBB\x82\xEA\x82\xCD"
        "\x81\x41\x96\xE9\x82\xB2\x82\xC6\x89\xCC\x82\xA4\x8C\xB6\x82\xCC"
        "\x89\xCC\x95\x50\x81\x67\x8F\xAD\x8F\x97\x41\x81\x68\x82\xCC\x93"
        "\x73\x8E\x73\x93\x60\x90\xE0\x81\x42\x0A\x0A\x82\xBB\x82\xCC\x89"
        "\x5E\x96\xBD\x82\xCC\x96\xE9\x81\x5C\x81\x5C\x0A\x0A\x93\xB5\x82"
        "\xCC\x92\x86\x82\xC9\x8C\xBB\x82\xEA\x82\xE9\x81\x67\x8F\xAD\x8F"
        "\x97\x41\x81\x68\x82\xC9\x93\xB1\x82\xA9\x82\xEA\x81\x41\x0A\x90"
        "\xDA\x91\xB1\x8E\xD2\x82\xC6\x82\xB5\x82\xC4\x8A\x6F\x90\xC1\x82"
        "\xB5\x82\xBD\x90\x90\x98\x61\x20\x8B\xC5\x90\x6C\x82\xCD\x81\x41"
        "\x0A\x94\x70\x9A\xD0\x82\xCC\x92\xB8\x82\xC5\x8C\xA9\x92\x6D\x82"
        "\xE7\x82\xCA\x81\x67\x93\xAF\x96\x45\x81\x68\x82\xBD\x82\xBF\x82"
        "\xC6\x8F\x6F\x89\xEF\x82\xA4\x81\x42\x0A\x0A\x0A\x81\x75\x92\x87"
        "\x8A\xD4\x82\xB6\x82\xE1\x82\xC8\x82\xA2\x82\xCC\x81\x48\x81\x76"
        "\x81\x40\x92\x7C\x89\xCD\x20\x8D\x67\x8F\x8F\x81\x5E\x81\x67\x90"
        "\xB3\x8B\x60\x82\xCC\x96\xA1\x95\xFB\x81\x68\x0A\x0A\x81\x75\x93"
        "\x66\x82\xAB\x8B\x43\x82\xAA\x82\xB7\x82\xE9\x82\xD9\x82\xC7\x90"
        "\xC2\x8F\x74\x8F\x4C\x82\xA2\x81\x76\x81\x40\x97\x4D\x89\xD4\x20"
        "\x90\x5E\x90\xE1\x81\x5E\x81\x67\x82\xA4\x82\xBB\x82\xC2\x82\xAB"
        "\x81\x68\x0A\x0A\x81\x75\x91\x81\x82\xAD\x8B\x41\x82\xE8\x82\xBD"
        "\x82\xA2\x82\xE6\x82\xCB\x82\xA6\x81\x76\x81\x40\x8F\x74\x93\xFA"
        "\x95\x94\x20\x8F\x74\x81\x5E\x81\x67\x8B\x55\x83\x81\x83\x43\x83"
        "\x68\x81\x68\x0A\x0A\x81\x75\x83\x68\x83\x57\x93\xA5\x82\xDD\x82"
        "\xE2\x82\xAA\x82\xC1\x82\xBD\x82\xE7\x8E\x45\x82\xB7\x82\xBC\x81"
        "\x76\x81\x40\x88\xC9\x91\xF2\x20\x94\x8B\x81\x5E\x81\x67\x83\x60"
        "\x83\x93\x83\x73\x83\x89\x81\x68\x0A\x0A\x0A\x8F\x89\x82\xDF\x82"
        "\xC4\x8F\x6F\x89\xEF\x82\xC1\x82\xBD\x35\x90\x6C\x82\xCC\x8A\xD4"
        "\x82\xC9\x82\xCD\x81\x41\x97\x46\x8F\xEE\x82\xE0\x81\x41\x90\x4D"
        "\x97\x8A\x82\xE0\x81\x41\x89\xBD\x82\xE0\x82\xC8\x82\xA2\x81\x42"
        "\x0A\x0A\x82\xBE\x82\xAA\x81\x42\x0A\x0A\x35\x90\x6C\x82\xCC\x90"
        "\xDA\x91\xB1\x8E\xD2\x82\xA9\x82\xE7\x82\xC8\x82\xE9\x81\x67\x8F"
        "\x57\x92\x63\x81\x73\x83\x52\x83\x7E\x83\x85\x81\x74\x81\x68\x82"
        "\xCD\x81\x41\x0A\x97\xCD\x82\xF0\x8D\x87\x82\xED\x82\xB9\x82\xE9"
        "\x82\xB1\x82\xC6\x82\xC5\x81\x41\x8B\x90\x91\xE5\x82\xC8\x81\x67"
        "\x8D\x7C\x82\xCC\x89\xF6\x95\xA8\x81\x73\x83\x41\x83\x6F\x83\x5E"
        "\x81\x5B\x81\x74\x81\x68\x82\xF0\x88\xD3\x82\xCC\x82\xDC\x82\xDC"
        "\x82\xC9\x91\x80\x82\xE9\x82\xB1\x82\xC6\x82\xAA\x89\xC2\x94\x5C"
        "\x82\xC9\x82\xC8\x82\xE9\x81\x42\x0A\x0A\x8E\xBD\x8D\x95\x82\xCC"
        "\x83\x41\x83\x6F\x83\x5E\x81\x5B\x81\x67\x83\x6F\x83\x72\x83\x8D"
        "\x83\x93\x81\x68\x82\xC6\x90\xDA\x91\xB1\x82\xB3\x82\xEA\x81\x41"
        "\x8B\xAD\x91\xE5\x82\xC8\x97\xB3\x82\xCC\x97\xCD\x82\xF0\x8E\xE8"
        "\x82\xC9\x82\xB5\x82\xBD\x82\xBB\x82\xCC\x93\xFA\x82\xA9\x82\xE7"
        "\x81\x41\x0A\x8B\xC5\x90\x6C\x82\xBD\x82\xBF\x82\xCC\x91\x4F\x82"
        "\xC9\x96\x4B\x82\xEA\x82\xE9\x81\x41\x8D\x72\x81\x58\x82\xB5\x82"
        "\xAB\x94\xF1\x93\xFA\x8F\xED\x81\x42\x0A\x0A\x0A\x97\xB3\x82\xF0"
        "\x91\x5F\x82\xA4\x89\xF6\x95\xA8\x82\xBD\x82\xBF\x81\x41\x90\xB9"
        "\x8B\x52\x8E\x6D\x82\xCC\x97\x88\x96\x4B\x81\x41\x82\xBB\x82\xB5"
        "\x82\xC4\x94\x65\x89\xA4\x82\xCC\x8C\x52\x90\xA8\x81\x5C\x81\x5C"
        "\x0A\x0A\x0A\x82\xBB\x82\xEA\x82\xCD\x35\x90\x6C\x82\xF0\x81\x41"
        "\x90\x6C\x92\x6D\x82\xEA\x82\xCA\x81\x67\x83\x52\x83\x7E\x83\x85"
        "\x82\xCC\x90\xA2\x8A\x45\x81\x73\x83\x52\x83\x7E\x83\x85\x83\x6C"
        "\x83\x62\x83\x67\x81\x74\x81\x68\x82\xD6\x82\xC6\x97\x55\x82\xC1"
        "\x82\xBD\x81\x42\x0A\x0A\x82\xBB\x82\xB5\x82\xC4\x8B\xC5\x90\x6C"
        "\x82\xCD\x92\x6D\x82\xE9\x81\x42\x0A\x97\xCD\x82\xC9\x82\xCD\x91"
        "\xE3\x8F\x9E\x82\xAA\x95\x4B\x97\x76\x82\xBE\x82\xC1\x82\xBD\x81"
        "\x42\x0A\x0A\x83\x41\x83\x6F\x83\x5E\x81\x5B\x82\xAA\x96\xC5\x82"
        "\xD4\x82\xC6\x82\xAB\x81\x41\x0A\x90\xDA\x91\xB1\x82\xB3\x82\xEA"
        "\x82\xBD\x81\x67\x8F\x57\x92\x63\x81\x73\x83\x52\x83\x7E\x83\x85"
        "\x81\x74\x81\x68\x82\xE0\x82\xDC\x82\xBD\x81\x41\x96\xC5\x82\xD4"
        "\x81\x42\x0A\x0A\x0A\x82\xBB\x82\xCC\x89\x5E\x96\xBD\x82\xCC\x96"
        "\xE9\x81\x5C\x81\x5C\x0A\x0A\x0A\x95\x73\x8F\xF0\x97\x9D\x82\xC9"
        "\x8C\x71\x82\xAA\x82\xEA\x82\xBD\x8B\xC5\x90\x6C\x82\xCD\x81\x41"
        "\x0A\x81\x67\x8D\x95\x82\xCC\x96\x82\x8F\x97\x81\x68\x94\xE4\x93"
        "\xDE\x90\x44\x20\x83\x4A\x83\x53\x83\x81\x82\xCC\x97\xCD\x82\xF0"
        "\x8E\xD8\x82\xE8\x82\xC4\x81\x41\x0A\x82\xDC\x82\xBE\x8C\xA9\x82"
        "\xCA\x90\xA2\x8A\x45\x82\xC9\x97\xA7\x82\xBF\x8C\xFC\x82\xA9\x82"
        "\xA4\x81\x42\x0A\x0A\x0A\x81\x75\x82\xBB\x82\xEA\x82\xC5\x82\xE0"
        "\x89\xB4\x82\xBD\x82\xBF\x82\xCD\x83\x60\x81\x5B\x83\x80\x82\xBE"
        "\x81\x42\x0A\x81\x40\x82\xBD\x82\xC6\x82\xA6\x89\xB4\x82\xBD\x82"
        "\xBF\x82\xF0\x8C\x71\x82\xAE\x82\xCC\x82\xAA\x81\x41\x82\xB1\x82"
        "\xCC\x8D\x7C\x82\xCC\x89\xBB\x82\xAF\x95\xA8\x82\xBE\x82\xAF\x82"
        "\xBE\x82\xC6\x82\xB5\x82\xC4\x82\xE0\x81\x76\x0A\x0A\x0A\x93\xB9"
        "\x89\xBB\x82\xC6\x96\x82\x8F\x97\x82\xC6\x34\x90\x6C\x82\xCC\x92"
        "\x87\x8A\xD4\x81\x73\x83\x52\x83\x7E\x83\x85\x81\x74\x82\xCC\x81"
        "\x41\x92\xB7\x82\xA2\x97\xB7\x82\xAA\x8E\x6E\x82\xDC\x82\xE9\x81"
        "\x42\x0A\x0A\x0A\x0A\x81\x5C\x81\x5C\x82\xB3\x82\xA0\x81\x41\x8D"
        "\xA1\x96\xE9\x82\xCC\x82\xA8\x82\xC6\x82\xAC\x98\x62\x82\xF0\x82"
        "\xCD\x82\xB6\x82\xDF\x82\xE6\x82\xA4\x0A\x3C\xDD\x5A\x43\x1E\xE0"
        "\x80\xCD\x92\xD6\x44\xAA\xB9\x40\x7B\x02\xE4\xD8\x8A\x08\x36\x62"
        "\xE6\x9F\xC6\x95\xF7\x94\xCE\x44\x0A\x34\xB3\x82\x3D\xD2\x9E\x10"
        "\x5E\x4E\x83\xB1\x5D\x6E\x3F\x10\x48\x6A\xBF\xF3\x70\xF0\x32\xB2"
        "\x91\xC7\x01\xF6\x19\x03\x7C\x70\x84\x8C\x74\x50\xC5\x7F\x47\xB2"
        "\xFB\x1F\x2C\x38\x11\xB9\x2B\x12\x80\xCC\x70\x1E\xE3\xBF\x98\x4B"
        "\x05\xDA\x3F\xEE\xD0\xCD\x29\xF1\x6C\xC8\xB6\x80\xF7\xDF\x4A\x5D"
        "\x3B\xC7\x5F\xCA\xFA\xF1\x9B\xB5\x2C\xEE\x49\x16\x31\x9D\x05\xD9"
        "\xCD\x26\x0D\x31\xAF\x45\x0D\x5D\xE3\x36\x35\xD0\xAA\xDA\x2D\x43"
        "\x65\xF7\xD5\x5F\xF1\x7F\x43\x53\xD6\x71\xF0\xAA\x6C\xC5\x38\x9D"
        "\x39\xF7\x80\x76\x9C\x6B\x86\x0C\x8C\x33\x2F\x90\x0B\xEE\xBB\x12"
        "\x04\xDE\xDC\x81\x3A\x51\x29\x55\x4D\x87\x9F\xFC\x2A\xB3\xB6\xDA"
        "\x2E\x40\x2C\x3D\x03\x7E\x15\x2A\xB2\x76\x79\xF7\x98\xD9\x00\x93"
        "\x24\x32\x03\xBE\xE9\x28\x69\x2C\xF6\xA5\x62\xD5\x84\x7D\xC7\x19"
        "\xA3\x9C\x0B\x52\x10\xC0\xFF\x39\x33\xB5\xBA\xCE\x25\xF2\xAF\x1E"
        "\x2A\xAC\x30\xB9\xD6\x2A\xF3\x8A\xC6\x55\x5C\x02\x58\x88\x87\xB4"
        "\xA5\xA2\x2F\xAC\xD8\xD9\xCC\xFE\x9F\xFE\x2E\xE2\x5B\x62\x9F\x61"
        "\x49\x58\x0A\x29\x3F\xD2\xC7\x74\x4B\x77\xB2\xFF\xE7\xBF\xA5\xAB"
        "\x55\xF5\x67\x45\xC2\xC5\x5B\x11\x1B\xC0\xE4\x46\x66\xA3\x69\x5F"
        "\x0F\x27\xCE\xC8\xB5\x9B\x3F\x17\xA1\x6A\x8D\x61\x18\x5F\xA6\x54"
        "\x67\x34\xDC\x94\x29\x05\x1B\xE0\x71\xC0\x80\x5C\x34\x48\xEB\xDD"
        "\x56\xE1\x9D\x63\xBC\x0A\x76\x72\xFE\x68\x2B\x1F\xD5\xBE\x53\x46"
        "\x22\xDA\xC6\xBF\xB9\xEA\xD2\x1B\x3E\xC5\x78\x30\x1A\x25\x58\xF5"
        "\x55\xCD\x1C\xDE\x2B\x70\xC8\xC6\x28\x07\x1E\x45\xCA\x70\xB6\x1D"
        "\xE3\x3E\x36\xE9\x08\xAD\x59\x47\xF4\xEC\x5A\xD0\x40\xA3\xF5\xE5"
        "\x3F\x88\x72\x9F\x42\x0B\xEC\x2C\xAC\xBA\x0B\x62\x3B\xA1\xFF\x07"
        "\xCD\x94\x7E\x37\x6C\x0C\x5E\xBE\x88\x65\xB5\x4B\x42\xFE\xDD\xBF"
        "\x0F\xC4\x5C\x1F\x01\x67\xA5\x0F\x16\x6F\x6B\x1A\x7C\xCF\x03\xCB"
        "\x00\x0B\x83\xFA\xBE\x33\x50\x9C\xB3\x24\x1A\x59\x8D\xC6\x3C\x59"
        "\x54\xF6\x6B\xEF\xEB\x96\x12\x9C\xCD\x6D\xCC\xA4\xF8\xCB\x5B\x2F"
        "\xF7\xAD\x91\xCF\xFE\xB6\xE6\x51\xC2\xE2\x34\x32\xF8\xA2\x96\x0E"
        "\x2F\xA6\xC4\xA0\x5B\x2D\xDE\x56\x05\x90\xC1\x3B\xDD\x80\x62\x0F"
        "\x7C\x94\xF7\x1D\x8F\x8F\x77\xF3\x17\x6A\xFC\x12\x9A\x78\xB2\x7A"
        "\xD7\x33\x8F\x58\xFC\xC7\x90\x97\x4B\x76\xDD\x2E\xAA\x94\xC8\xAA"
        "\xB2\x1F\x85\xCB\x98\x77\x32\xEC\xA6\x2C\x03\xDE\x5D\xC7\x97\x90"
        "\x97\x7D\x78\xA2\x4F\xCF\xED\xF7\xFE\xFF\x9A\xB1\xC8\x49\x01\xD8"
        "\x8A\xF2\xA5\xD5\x75\x71\x46\x67\xFA\x2D\x5C\xC8\x94\x5E\x26\x64"
        "\xCC\xB9\x90\x9D\x2A\x99\x00\xE5\xD2\xA2\x88\x8C\x60\x30\xC5\x6B"
        "\x51\x42\x40\x9C\x41\xBE\xFB\x96\xE0\x36\x9E\x4B\xD0\x13\xCE\xE3"
        "\x69\xB1\x4B\xEA\xB5\x4B\x77\xA5\x7D\xAB\xF5\x0A\x9F\x2F\x6F\xD4"
        "\x4F\xEC\x12\x95\x81\x36\x98\x3C\x27\xD1\x45\x65\xAA\x3E\xD7\x39"
        "\xA5\x41\xA3\xF1\x6D\x8D\xD8\xBE\x7B\x66\x0A\xBC\x07\xC4\x81\xC0"
        "\x16\xE0\x81\xB7\xDC\xD4\xB9\x04\xC7\x9F\xB0\x25\x0E\x0A\x9B\x68"
        "\xB8\x9D\x13\xEA\xD3\xDC\xA6\x89\xAB\x44\x2F\x32\x6E\x29\x3F\xA4"
        "\x19\xCF\x33\x10\xCD\xAB\xA1\x5C\x49\x65\x44\x82\x3B\x0A\xC8\xC6"
        "\x02\xF6\x2C\xB6\xAA\xCD\x81\xB8\x90\xDF\x5F\x96\x7E\x34\xAF\xD7"
        "\x73\x32\x91\xBF\x53\x0A\xD5\x71\xB8\xAC\xE8\x07\xC5\xA2\x9E\x6E"
        "\x77\xD8\x53\x36\x9D\xB2\x84\x0A\xB2\xFF\x80\xF1\x34\x0B\x2F\x46"
        "\x3E\x92\x5B\xEA\x2F\xDC\x1C\xDB\xF8\xFC\x96\xBF\xC5\x3A\xE7\xFD"
        "\x09\xDF\x80\x51\x29\xF8\x23\xDA\xDD\xB2\x75\xE5\x94\xD9\x2E\x61"
        "\x8C\xA0\x32\x47\xB9\x5C\x96\xF3\x3C\xC9\x1F\xCB\x94\x40\x6A\xA3"
        "\x86\xBC\xB0\x11\x8C\xDA\xF6\x80\x1F\x2A\xA8\x95\x60\x9A\xF0\x2A"
        "\xEF\x1E\xCE\x26\x5B\xC9\xF1\x54\x10\x87\xE7\xE3\x74\xF3\xD5\x7A"
        "\xBA\xF6\xE3\x85\x1E\x6A\xD8\x6C\x8B\x2E\x96\x68\x44\xE5\x7E\x8B"
        "\xA1\x95\xDA\x54\x16\xB6\x34\x00\xFF\x6B\x55\xBF\x79\x78\x6C\xA8"
        "\x88\x14\x2E\xBE\x76\x4F\x67\x21\x59\xC7\x11\x17\x3F\x8C\xA3\xAF"
        "\xBD\xCE\x12\xB6\xAB\xCD\xF7\x0B\xAA\xD5\xD3\x5D\xF9\xC9\xB3\x5E"
        "\x77\xF4\xF9\x74\x00\x71\x97\x76\xA3\x94\xFF\x06\x90\x7D\xCF\xB7"
        "\x75\xDA\x1A\x46\x61\xF7\xA8\x90\xD8\x33\x32\x0C\xE2\xE2\x85\x8C"
        "\x91\x08\xC1\xB1\x0F\xD0\x6D\x15\x4B\x89\x98\x95\x10\x76\x96\x15"
        "\x3C\x5B\xE9\x00\xA1\x36\x78\xEA\x52\x3A\xD7\xC4\xB2\xC4\x01\xF8"
        "\x23\x84\xD6\xC3\xB7\xBB\x47\xEE\xB2\x98\xAC\xAC\xD6\x88\x52\x62"
        "\x0A\x97\x3A\xF3\x3D\xDC\xDC\xCA\xA4\x30\x65\x4D\x7D\xC1\x08\x8C"
        "\x11\xB0\x9D\x7D\x90\x0A\x12\x43\x91\x0E\x5A\xD8\xD0\x5D\x1C\x0A"
        "\xAE\x6C\x0A\x14\x46\x91\x1C\xB7\xF1\x35\x5D\xB7\x9C\xC6\x9E\x07"
        "\xD0\xAC\x4E\x44\x87\xE4\x92\x2C\xF0\x49\x8A\x76\x52\xDC\x67\x3C"
        "\xC4\xF8\xFB\xEC\x53\x11\x95\xC6\x6C\x67\x4A\x10\xB9\x7C\x70\x6A"
        "\xEC\x18\x37\x64\xDD\x0A\x1C\x83\x33\xBA\x63\xAB\x70\x85\x65\x7D"
        "\xC3\x6C\x07\x87\xD0\xDC\xF9\xF7\xE1\x39\x13\x7F\xE5\x26\xEC\x3C"
        "\x81\xE8\x27\x3B\x27\x7B\x90\xF7\xBA\x29\xB4\x9F\xC4\xAC\x8F\xF4"
        "\x24\xD3\xD5\xB7\xAA\x05\x8D\x0B\xDC\x36\x5D\x3D\x74\xD7\xC2\xC5"
        "\x73\x27\x73\x2B\x4D\xCE\x47\x0B\x7C\x5D\x9F\x0B\xBB\xF5\x7F\x1E"
        "\x21\x35\x95\xCE\x95\xF3\x6A\xB6\x6E\x28\x65\x89\x3D\x78\xFA\x24"
        "\x27\xF0\x04\x5B\xBE\xBB\x07\x86\x16\x78\xF9\x10\x19\x9E\xF8\xEB"
        "\x5A\x72\x59\x35\x26\x14\x3B\x00\xCC\x6F\xFB\xB1\xEC\x07\xDD\x9A"
        "\x28\x37\x15\xC4\xA8\x92\xA8\x03\x27\x29\xE9\xE2\xF1\xA3\xFC\x8D"
        "\x16\xFE\x98\xB8\x99\xA5\x85\x97\x40\x90\x30\x6D\x81\x43\x48\xBF"
        "\x15\x6E\x78\xB7\xA0\x62\xC3\xC0\x91\x69\xC1\xB8\x2F\x17\xD4\x1E"
        "\x1C\xDF\x4D\x3A\x2E\x4A\x0A\x7C\x17\xA3\xBD\x07\x01\x02\x80\xEB"
        "\x8F\x60\xD1\xC3\x92\x84\xC8\x51\xCD\xBF\x10\x0D\x90\xE2\x1C\xC8"
        "\xF8\x72\x75\x1C\x66\x7D\x54\xF4\x73\x05\x2F\xCA\xB0\xEC\x48\x4C"
        "\x8D\xEB\xD9\xD2\x26\x8F\x6B\x8D\x66\xDB\xAC\xE0\x26\xEE\x83\x3E"
        "\x4A\x14\xA4\x58\xD9\xB7\xC0\x16\x47\x55\x44\x99\x3D\x7C\xED\xE5"
        "\xD8\xFD\x9C\x9C\x21\x32\x21\xCF\xFA\x7F\xBF\xC5\x87\x78\x8F\xBF"
        "\xC7\xFA\x3F\xFC\x30\xFA\xBF\xD2\xE0\x78\xBF\xEA\x77\x46\xC9\x7C"
        "\x91\xDF\xEC\xF0\xD5\xBC\x85\xB5\xBD\xB2\x54\x33\x8B\x56\x07\x77"
        "\x68\xEA\xC3\x15\x2C\xC9\x95\xD7\x08\x65\xC8\xB5\x33\x9D\x12\xA9"
        "\x58\xD8\x5A\xFF\x2D\x17\x09\x32\xA7\xBD\x91\xB6\x23\x9C\xF6\x52"
        "\xA7\x6F\x7B\xCA\xCF\x79\xCE\x2A\x21\xB8\xEC\xB8\x86\xE9\x0B\x2A"
        "\xE3\x05\xA2\x93\xD4\x69\x1C\x5D\x32\x2F\x56\x5D\x4D\x76\x0C\xAE"
        "\x26\x28\xCD\xD3\x9F\x49\x34\xF4\xB2\xA3\x39\x03\x9E\x67\x51\x14"
        "\x8E\x98\xCF\x24\xFB\x72\x49\x22\xFD\x28\x62\xCB\xA3\xE1\x9F\xBE"
        "\x19\x59\x1F\xBA\x46\x47\xB8\xB2\x42\x1A\xC2\x4E\xB9\x59\x8F\x6B"
        "\x37\x86\x72\xB0\xA8\x42\x67\xAE\xBE\xF0\xB0\xB9\x4A\xB1\x46\x5C"
        "\xB7\x8A\x59\x64\xD5\x07\x71\x25\x20\xA2\xB0\xA1\xAE\xD1\xC9\x78"
        "\xFF\x57\xB0\x5A\x02\xF1\xE8\x85\x29\xE1\x50\x61\x84\xCD\x5C\x34"
        "\x8F\xF5\x4B\xF1\x9E\xA1\xB7\x93\xAC\x9C\x7E\x4A\x91\xCA\xC5\xEA"
        "\x9E\x6A\x31\x19\x97\xE5\xBF\xFF\xCC\x9A\xBB\x12\xD0\x5F\x13\xB5"
        "\xFF\xF7\x59\xDC\xF8\x80\x27\x83\x5D\x64\xBB\x99\x80\x10\x8C\x02"
        "\xDC\x9F\xA0\xA7\x69\x6E\xB1\x35\x04\xFC\x68\x80\xB6\xA5\x5F\xA3"
        "\xBC\x18\x27\x70\x0D\x74\x33\xD3\x3A\xB0\xCB\xF5\xBA\xF4\x7D\x57"
        "\xCA\xAC\x10\x92\xE9\x5F\xAA\x96\x06\x7C\x55\xF3\xDD\x34\x76\x16"
        "\x7E\xDB\xB2\xBF\x5C\xA1\x5E\x03\x13\xC8\xA5\x57\x63\xCA\x89\x53"
        "\xF8\xD9\x74\xBE\xF3\x4A\xDA\xE7\x09\xB6\x14\xB6\xD5\x6F\xB4\xB8"
        "\x91\x1C\xB6\x2B\x69\xAE\x03\x69\xB6\x08\xC6\x8A\x63\x6B\xF7\x22"
        "\x1D\x03\x45\x4E\x03\x6B\x33\x7C\x87\x58\x0A\x59\xF0\x54\x9B\x4E"
        "\x67\x4C\x07\xBF\xF8\x48\xBE\x1D\x9A\xA1\xAD\x35\xA5\x03\x20\xF9"
        "\x54\xDD\x80\x40\xE9\x41\xFD\xC3\x91\xD4\xB1\x6F\x82\x20\x6F\x97"
        "\x73\x9D\xDC\x06\xB6\xEC\xF1\x8C\xCA\x45\xEC\xB7\x9B\xA3\x34\x1B"
        "\xFB\x1B\x35\xE0\xFC\xCA\x11\xA7\x97\xE0\x88\x9E\xE7\x26\xB7\xED"
        "\x6D\x07\x6F\x10\x23\x31\x1F\x78\x50\xFE\x6C\x4E\x76\x30\xF2\xB3"
        "\x73\xC6\x7A\x12\x52\xEE\xA0\x2F\x35\x46\x0D\x72\x3B\x0C\xCF\xBB"
        "\xA1\x92\x7D\xC4\xFE\xEC\x73\x65\x90\x68\xA8\x85\x4F\x13\x73\xB1"
        "\xF4\x7B\x65\x4B\x9A\x67\x9E\x6F\x34\xA4\x27\x8D\x00\xFF\xA7\x72"
        "\xF1\x22\xDC\xC6\xA2\x0A\xDA\xAC\xBC\x63\x70\x7E\x61\x39\x10\xC2"
        "\xB8\x9C\xF3\x07\x12\x72\x3E\x84\x13\x9D\xD2\x8F\x5C\xFA\x03\x15"
        "\x50\x16\x2F\x66\x75\x19\xB4\xFA\x62\xE3\xA7\xEF\x6E\xE0\xE6\x80"
        "\x8B\x9D\x85\x53\x12\xD1\xDE\x9B\xF5\x26\xC7\x30\x79\x14\xEC\x3D"
        "\x46\xA7\x32\xD3\xFB\x40\xF6\x40\x8B\xB0\x84\x91\xF7\x2F\x68\x94"
        "\x63\x18\x81\xD3\x31\x18\x7D\x48\xE2\x19\xEB\xBE\x44\x9F\x2E\x04"
        "\xA1\x6F\xF3\x73\xF3\xE3\xFB\x42\xDA\x97\x54\x32\x65\x1E\x9C\xAC"
        "\xB4\x3A\xCE\x2C\x5B\x73\x5D\x63\xF5\x26\x73\x06\x41\x89\xB6\x1C"
        "\x2E\xE0\x16\x2B\x74\x7F\x1D\x1B\x15\x36\x67\xB2\xF5\x2A\xDC\x39"
        "\xB9\xF5\xE9\x98\xE3\x4E\x06\xB5\x0E\x7E\xC9\xEC\x03\x90\x1C\xC8"
        "\x64\x69\xC1\x8A\xFB\xE5\x0E\x26\x05\xC4\x8E\xF8\xD5\xD4\x47\x81"
        "\xC0\xFD\x21\x36\xDD\xAB\xD3\xDD\x0F\x58\x58\x67\xB6\xC5\xB7\x9F"
        "\x4C\xD5\x1E\x71\xC6\xE8\xA5\x14\xB6\x87\xB2\x7C\x08\x21\x3D\x9F"
        "\xAA\x4C\x5D\xB9\xE1\x2F\x31\x9E\x31\x6C\x73\xF4\x46\x52\x21\x8F"
        "\x70\x7D\x3A\x03\x97\xDE\xFA\x3A\x4A\x1D\x0E\xCC\x79\xE7\x44\xBF"
        "\xF0\x6D\xD4\xD7\x5D\x17\x66\x90\xFD\x99\x51\xA0\x75\x9E\xCD\x46"
        "\x31\x81\xBC\xE8\x85\xF4\xE8\xC2\x76\x24\x73\x7A\xD2\x64\x88\x26"
        "\x1A\x93\xD3\x0B\x10\x5C\x78\x8D\xD4\xE4\x29\x10\xEA\xA9\x6E\x48"
        "\x74\x44\x05\x5E\x7A\xBA\x23\x98\x05\x91\xB4\x2A\xC2\xAA\xF6\x17"
        "\xC7\x04\x2C\x53\x90\x13\xB1\xC4\x9A\xCE\xBA\xEC\x0E\x47\x7A\x6F"
        "\x30\x3C\x54\x83\xB7\xC4\x6E\x2E\x83\x6D\x27\x17\xCE\xCD\x40\xED"
        "\x29\xC8\xB0\x40\xC5\xA0\xB1\x88\xC3\x67\xD6\xED\xCF\x9C\x0F\xD4"
        "\x03\x06\x25\x0E\xFE\xE7\x63\x06\x80\x53\x07\xCC\x4D\xB4\x6C\x16"
        "\x87\x2C\xCB\x4A\xED\x6E\xAA\x00\x6D\x38\x21\x34\xEF\xE6\xED\x69"
        "\x8C\x50\x8B\x36\x53\xA1\xDF\x0C\x32\xB5\xF7\x2F\x6A\xDF\x14\x53"
        "\xEC\x11\x37\x7C\xC9\x69\xA5\x97\x37\x27\x56\x75\x83\xA0\x98\xC0"
        "\xAF\x0E\x7E\x48\xA4\x32\x03\xED\x65\x85\x98\xE0\xA7\x8C\x27\x3C"
        "\xE4\x7C\xC6\x63\xDC\xD4\xBB\x3D\x04\x76\x32\x66\x75\xE0\xD6\x44"
        "\x65\xF6\xF7\x24\x30\x5C\xC4\x16\xE2\x8C\x12\xDC\x56\x10\x56\xA9"
        "\xD4\x08\x9B\xA1\xC0\xD3\xDC\xA3\x4B\x44\x76\x04\x04\x0A\x47\x1E"
        "\xBB\x54\x74\x2F\x77\x48\xAA\x61\xCE\x26\xA1\xEF\x20\x94\x17\xC8"
        "\xEF\x10\xF1\xEE\xA1\xE2\x8A\x50\x98\x2B\xC7\x9C\xF1\x8B\x17\x7F";

    CxdecFilter cxdec(settings);
    cxdec.decode(file, key);
}
