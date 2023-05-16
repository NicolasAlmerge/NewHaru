#include "../include/DateTime.hpp"
using namespace pdf;


DateTime::DateTime() noexcept: DateTime(0, 0, 0, 0, 0, 0) {}

DateTime::DateTime(
    int year, int month, int day,
    int hour, int minutes, int seconds, UTCIndicator ind,
    int offHour, int offMinutes
) noexcept {
    innerContent.year = year;
    innerContent.month = month;
    innerContent.day = day;
    innerContent.hour = hour;
    innerContent.minutes = minutes;
    innerContent.seconds = seconds;
    innerContent.ind = (char) ind;
    innerContent.off_hour = offHour;
    innerContent.off_minutes = offMinutes;
}

int DateTime::getYear() const noexcept {
    return innerContent.year;
}

int DateTime::getMonth() const noexcept {
    return innerContent.month;
}

int DateTime::getDay() const noexcept {
    return innerContent.day;
}

int DateTime::getHour() const noexcept {
    return innerContent.hour;
}

int DateTime::getMinutes() const noexcept {
    return innerContent.minutes;
}

int DateTime::getSeconds() const noexcept {
    return innerContent.seconds;
}

UTCIndicator DateTime::getUTCIndicator() const noexcept {
    switch (innerContent.ind) {
        case '+': return UTCIndicator::PLUS;
        case '-': return UTCIndicator::MINUS;
        case 'Z': return UTCIndicator::Z;
        default: return UTCIndicator::NONE;
    }
}

int DateTime::getOffHour() const noexcept {
    return innerContent.off_hour;
}

int DateTime::getOffMinutes() const noexcept {
    return innerContent.off_minutes;
}

bool DateTime::isEmpty() const noexcept {
    return false;
}
