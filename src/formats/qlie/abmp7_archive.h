#ifndef FORMATS_QLIE_ABMP7_ARCHIVE_H
#define FORMATS_QLIE_ABMP7_ARCHIVE_H
#include "formats/archive.h"

namespace Formats
{
    namespace QLiE
    {
        class Abmp7Archive final : public Archive
        {
        protected:
            bool is_recognized_internal(File &) const override;
            void unpack_internal(File &, FileSaver &) const override;
        };
    }
}

#endif
