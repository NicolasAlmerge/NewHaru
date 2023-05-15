#ifndef __HARUPP_DATETIME_HPP__
#define __HARUPP_DATETIME_HPP__
#include "Constants.hpp"
#include "hpdf.h"

namespace pdf {
    class PdfDocument;

    class DateTime final {
        _HPDF_Date innerContent;
        friend class PdfDocument;

    public:
        DateTime();
        DateTime(
            int year, int month, int day,
            int hour, int minutes, int seconds, UTCIndicator ind = UTCIndicator::NONE,
            int offHour = 0, int offMinutes = 0
        );

        int getYear() const;
        int getMonth() const;
        int getDay() const;
        int getHour() const;
        int getMinutes() const;
        int getSeconds() const;
        UTCIndicator getUTCIndicator() const;
        int getOffHour() const;
        int getOffMinutes() const;
    };
}

#endif // __HARUPP_DATETIME_HPP__
