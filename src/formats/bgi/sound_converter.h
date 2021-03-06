#ifndef FORMATS_BGI_SOUND_CONVERTER_H
#define FORMATS_BGI_SOUND_CONVERTER_H
#include "formats/converter.h"

namespace Formats
{
    namespace Bgi
    {
        class SoundConverter final : public Converter
        {
        protected:
            bool is_recognized_internal(File &) const override;
            std::unique_ptr<File> decode_internal(File &) const override;
        };
    }
}

#endif
