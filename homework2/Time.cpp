#include "Time.hpp"

ostream &operator<<(ostream &str, Time &rhs){
    str << rhs.hours << "h: "<< rhs.minutes << "m: "<< rhs.seconds << "s" << endl;
    return str;
}

istream &operator>>(istream &str, Time &rhs){
    str >> rhs.hours;
    str >> rhs.minutes;
    str >> rhs.seconds;
    return str;
}

Time Time::operator+(const Time& other) const {
    int totalSeconds = (hours * 3600 + minutes * 60 + seconds) +
                       (other.hours * 3600 + other.minutes * 60 + other.seconds);
    return Time(totalSeconds / 3600, (totalSeconds % 3600) / 60, totalSeconds % 60);
}

Time Time::operator-(const Time& other) const {
    int totalSeconds = (hours * 3600 + minutes * 60 + seconds) -
                       (other.hours * 3600 + other.minutes * 60 + other.seconds);
    return Time(totalSeconds / 3600, (totalSeconds % 3600) / 60, totalSeconds % 60);
}

Time Time::operator*(int scalar) const {
    int totalSeconds = (hours * 3600 + minutes * 60 + seconds) * scalar;
    return Time(totalSeconds / 3600, (totalSeconds % 3600) / 60, totalSeconds % 60);
}
