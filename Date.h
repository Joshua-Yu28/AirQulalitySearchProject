#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date {
public:
    Date();
    Date(int mm, int dd, int yy);
    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;

    void SetDay(int dd);
    void SetMonth(int mm);
    void SetYear(int yy);
    void SetDate(int mm, int dd, int yy);

    void printDate();

    Date& operator=(const Date& other);
    bool operator==(const Date& other) const;

private:
    int day;
    int month;
    int year;
};

ostream & operator <<( ostream & os, const Date & D );
istream & operator >>( istream & input, Date & D );

#endif // DATE_H
