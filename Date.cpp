#include "Date.h"
#include <iostream>

using namespace std;

Date::Date() {
    month = 1;
    day = 1;
    year = 2000;
}

Date::Date(int mm, int dd, int yy) {
    month = mm;
    day = dd;
    year = yy;
}

int Date::GetDay() const {
    return day;
}

void Date::SetDay(int dd) {
    day = dd;
}

int Date::GetMonth() const {
    return month;
}

void Date::SetMonth(int mm) {
    month = mm;
}

int Date::GetYear() const {
    return year;
}

void Date::SetYear(int yy) {
    year = yy;
}

void Date::SetDate(int mm, int dd, int yy) {
    month = mm;
    day = dd;
    year = yy;
}

void Date::printDate() {
    cout << "  Date:  " << month << " " << day << " " << year << '\n';
}

istream & operator >>(istream & input, Date & D) {
    char delim;
    int mm, dd, yyyy;

    input >> mm >> delim >> dd >> delim >> yyyy;

    D.SetMonth(mm);
    D.SetDay(dd);
    D.SetYear(yyyy);

    return input;
}


ostream& operator<<(std::ostream& os, const Date& date) {
    os << "Date: " << date.GetMonth() << "/" << date.GetDay() << "/" << date.GetYear();
    return os;
}

Date& Date::operator=(const Date& other) {
    if (this != &other) {
        this->month = other.month;
        this->day = other.day;
        this->year = other.year;
    }

    return *this;
}

bool Date::operator==(const Date& other) const {
    return (day == other.day && month == other.month && year == other.year);
}
