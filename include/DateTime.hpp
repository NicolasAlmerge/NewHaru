#ifndef __HARUPP_DATETIME_HPP__
#define __HARUPP_DATETIME_HPP__
#include "Constants.hpp"
#include "hpdf.h"

namespace pdf {
    class PdfDocument;

    class DateTime {
        _HPDF_Date innerContent;

    public:
        DateTime();
        DateTime(
            int year, int month, int day,
            int hour, int minutes, int seconds, UTCIndicator ind = UTCIndicator::NONE,
            int offHour = 0, int offMinutes = 0
        );

        friend class PdfDocument;
    };
}

#endif // __HARUPP_DATETIME_HPP__
