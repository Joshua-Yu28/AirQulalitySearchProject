#include<iostream>
#include "Time.h"
#include<iomanip>

using namespace std;

Time::Time()
{
	hour=0;
	min=0;
    sec = 0;
}
Time::Time(int hh, int mm, int ss)
{
	hour=hh;
	min=mm;
    sec=ss;
}
Time::~Time()
{
	//none
}
int Time::GetHour() const
{
	return hour;
}
int Time::GetMin() const
{
	return min;
}

int Time::GetSec() const
{
    return sec;
}

void Time::SetHour(int hh)
{
	hour=hh;
}

void Time::SetMin(int mm)
{
	min=mm;
}

void Time::SetSec(int ss) {
    sec=ss;
}

void Time::SetTime(int hh, int mm, int ss)
{
	hour=hh;
	min=mm;
    sec=ss;
}
void Time::printTime() {
    cout << "Time: " << setw(2) << setfill('0') << hour << ":"
         << setw(2) << setfill('0') << min << ":"
         << setw(2) << setfill('0') << sec;
}

istream & operator >>( istream & input, Time & T )
{
	string time,sHH,sMM, sSS;

	getline(input,sHH,':');
    getline(input, sMM,':');
	getline(input,sSS,'\n');

    try{
	    int hh=stoi(sHH);
	    int mm=stoi(sMM);
        int ss=stoi(sSS);

	    T.SetHour(hh);
	    T.SetMin(mm);
        T.SetSec(ss);
}catch(const invalid_argument& e) {
        cerr << "Error: Invalid input format for time." << endl;
        // Clear the input stream to discard remaining characters
        input.clear();
        // Ignore the rest of the line
        input.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return input;
}

ostream & operator <<( ostream & os, const Time & T )
{
    os <<"Time: "<< setw(2) << setfill('0') << T.GetHour() << ":"
       << setw(2) << setfill('0') << T.GetMin() << ":"
       << setw(2) << setfill('0') << T.GetSec();
    return os;
}

bool Time::operator==(const Time& other) const {
    return (hour == other.hour && min == other.min && sec == other.sec);
}

Time& Time::operator=(const Time& other) {
    if (this != &other) {
        this->hour = other.hour;
        this->min = other.min;
        this->sec = other.sec;
    }
    return *this;
}

