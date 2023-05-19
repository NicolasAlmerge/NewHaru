#include "../include/DateTime.hpp"
using namespace pdf;


DateTime::DateTime() noexcept {}

DateTime::DateTime(
    int year, int month, int day,
    int hour, int minutes, int seconds, enums::UTCIndicator ind,
    int offHour, int offMinutes
) noexcept: year(year), month(month), day(day), hour(hour), minutes(minutes),
    seconds(seconds), ind(ind),
    offHour((ind == enums::UTCIndicator::NONE)? 0: offHour),
    offMinutes((ind == enums::UTCIndicator::NONE)? 0: offMinutes) {}

int DateTime::getYear() const noexcept {
    return year;
}

int DateTime::getMonth() const noexcept {
    return month;
}

int DateTime::getDay() const noexcept {
    return day;
}

int DateTime::getHour() const noexcept {
    return hour;
}

int DateTime::getMinutes() const noexcept {
    return minutes;
}

int DateTime::getSeconds() const noexcept {
    return seconds;
}

enums::UTCIndicator DateTime::getUTCIndicator() const noexcept {
    return ind;
}

int DateTime::getOffHour() const noexcept {
    return offHour;
}

int DateTime::getOffMinutes() const noexcept {
    return offMinutes;
}

bool DateTime::isEmpty() const noexcept {
    return false;
}
