#ifndef FORMATS_TOUHOU_PAK1_IMAGE_ARCHIVE_H
#define FORMATS_TOUHOU_PAK1_IMAGE_ARCHIVE_H
#include "formats/archive.h"

namespace Formats
{
    namespace Touhou
    {
        class Pak1ImageArchive : public Archive
        {
        protected:
            bool is_recognized_internal(File &) const override;
            void unpack_internal(File &, FileSaver &) const override;
        };
    }
}

#endif
