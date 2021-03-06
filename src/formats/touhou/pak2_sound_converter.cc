// PAK2 sound file
//
// Company:   Team Shanghai Alice
// Engine:    -
// Extension: .cv3
//
// Known games:
// - Touhou 10.5 - Scarlet Weather Rhapsody
// - Touhou 12.3 - Unthinkable Natural Law

#include "formats/touhou/pak2_sound_converter.h"
#include "util/sound.h"
using namespace Formats::Touhou;

bool Pak2SoundConverter::is_recognized_internal(File &file) const
{
    return file.has_extension("cv3");
}

std::unique_ptr<File> Pak2SoundConverter::decode_internal(File &file) const
{
    auto format = file.io.read_u16_le();
    auto channel_count = file.io.read_u16_le();
    auto sample_rate = file.io.read_u32_le();
    auto byte_rate = file.io.read_u32_le();
    auto block_align = file.io.read_u16_le();
    auto bits_per_sample = file.io.read_u16_le();
    file.io.skip(2);
    size_t size = file.io.read_u32_le();

    auto sound = Sound::from_samples(
        channel_count,
        bits_per_sample / 8,
        sample_rate,
        file.io.read(size));
    return sound->create_file(file.name);
}
