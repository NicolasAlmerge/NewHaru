#include "../include/DateTime.hpp"
using namespace pdf;


DateTime::DateTime() {
    innerContent.year = 0;
    innerContent.month = 0;
    innerContent.day = 0;
    innerContent.hour = 0;
    innerContent.minutes = 0;
    innerContent.seconds = 0;
    innerContent.ind = ' ';
    innerContent.off_hour = 0;
    innerContent.off_minutes = 0;
}

DateTime::DateTime(
    int year, int month, int day,
    int hour, int minutes, int seconds, UTCIndicator ind,
    int offHour, int offMinutes
) {
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
