#ifndef FORMATS_KEY_NWA_CONVERTER_H
#define FORMATS_KEY_NWA_CONVERTER_H
#include "formats/converter.h"

namespace Formats
{
    namespace Key
    {
        class NwaConverter final : public Converter
        {
        protected:
            bool is_recognized_internal(File &) const override;
            std::unique_ptr<File> decode_internal(File &) const override;
        };
    }
}

#endif
