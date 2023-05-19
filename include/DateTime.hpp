#ifndef __HARUPP_DATETIME_HPP__
#define __HARUPP_DATETIME_HPP__
#include "Enums.hpp"
#include "Object.hpp"

namespace pdf {

    /**
     * \class  DateTime
     * @brief  Represents a date time.
     * @file   DateTime.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class DateTime final: public Object {
        int year = 0;
        int month = 0;
        int day = 0;
        int hour = 0;
        int minutes = 0;
        int seconds = 0;
        enums::UTCIndicator ind = enums::UTCIndicator::NONE;
        int offHour = 0;
        int offMinutes = 0;

    public:

        /**
         * @brief Creates a new DateTime.
         * @details This is equivalent to `DateTime(0, 0, 0, 0, 0, 0)`.
        */
        DateTime() noexcept;

        /**
         * @brief Creates a new DateTime with parameters.
         * @param year       Year to use.
         * @param month      Month to use.
         * @param day        Day to use.
         * @param hour       Hour to use.
         * @param minutes    Minutes to use.
         * @param seconds    Seconds to use.
         * @param ind        UTC indicator to use.
         * @param offHour    Offset hour to use. This will be set to `0` if `ind` equals enums::UTCIndicator::NONE.
         * @param offMinutes Offset minutes to use. This will be set to `0` if `ind` equals enums::UTCIndicator::NONE.
        */
        DateTime(
            int year, int month, int day,
            int hour, int minutes, int seconds, enums::UTCIndicator ind = enums::UTCIndicator::NONE,
            int offHour = 0, int offMinutes = 0
        ) noexcept;

        /**
         * @brief  Gets the year value.
         * @return Year value.
        */
        int getYear() const noexcept;

        /**
         * @brief  Gets the month value.
         * @return Month value.
        */
        int getMonth() const noexcept;

        /**
         * @brief  Gets the day value.
         * @return Day value.
        */
        int getDay() const noexcept;

        /**
         * @brief  Gets the hour value.
         * @return Hour value.
        */
        int getHour() const noexcept;

        /**
         * @brief  Gets the minutes value.
         * @return Minutes value.
        */
        int getMinutes() const noexcept;

        /**
         * @brief  Gets the seconds value.
         * @return Seconds value.
        */
        int getSeconds() const noexcept;

        /**
         * @brief  Gets the UTC indicator value.
         * @return UTC indicator value.
        */
        enums::UTCIndicator getUTCIndicator() const noexcept;

        /**
         * @brief  Gets the offset hour value.
         * @return Offset hour value.
        */
        int getOffHour() const noexcept;

        /**
         * @brief  Gets the offset minutes value.
         * @return Offset minutes value.
        */
        int getOffMinutes() const noexcept;

        /**
         * @brief Always returns `false`.
         * @return `false`
        */
        bool isEmpty() const noexcept override;
    };
}

#endif // __HARUPP_DATETIME_HPP__
