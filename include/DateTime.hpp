#pragma once
#include "hpdf.h"
#include "Constants.hpp"


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
