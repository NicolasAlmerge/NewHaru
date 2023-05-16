#ifndef __HARUPP_DATETIME_HPP__
#define __HARUPP_DATETIME_HPP__
#include "Constants.hpp"
#include "PdfObject.hpp"
#include "hpdf.h"

namespace pdf {
    class DateTime final: public PdfObject {
        _HPDF_Date innerContent;
        friend class PdfDocument;

    public:
        DateTime() noexcept;
        DateTime(
            int year, int month, int day,
            int hour, int minutes, int seconds, UTCIndicator ind = UTCIndicator::NONE,
            int offHour = 0, int offMinutes = 0
        ) noexcept;

        int getYear() const noexcept;
        int getMonth() const noexcept;
        int getDay() const noexcept;
        int getHour() const noexcept;
        int getMinutes() const noexcept;
        int getSeconds() const noexcept;
        UTCIndicator getUTCIndicator() const noexcept;
        int getOffHour() const noexcept;
        int getOffMinutes() const noexcept;

        bool isEmpty() const noexcept override;
    };
}

#endif // __HARUPP_DATETIME_HPP__
