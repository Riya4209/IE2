#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(){hours = 0; minutes = 0; seconds = 0;}

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    Time(const int &tseconds){
        hours = tseconds/3600;
        minutes = (tseconds % 3600) / 60;
        seconds = tseconds % 60;
    }

    friend std::ostream &operator<<(std::ostream &str, Time &rhs);
    friend std::istream &operator>>(std::istream &str, Time &rhs);

    Time operator+(const Time& other) const;
    Time operator-(const Time& other) const;
    Time operator*(int scalar) const;

    operator int() const{
        return hours * 3600 + minutes * 60 + seconds;
    }
};

#endif
