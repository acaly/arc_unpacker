#ifndef FORMATS_KIRIKIRI_TLG_TLG6_DECODER_H
#define FORMATS_KIRIKIRI_TLG_TLG6_DECODER_H
#include "file.h"

namespace Formats
{
    namespace Kirikiri
    {
        namespace Tlg
        {
            class Tlg6Decoder final
            {
            public:
                std::unique_ptr<File> decode(File &file);
            };
        }
    }
}

#endif
