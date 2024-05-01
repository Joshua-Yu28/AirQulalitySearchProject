#ifndef FINAL_PROJECT_AIRQUALITY_H
#define FINAL_PROJECT_AIRQUALITY_H

#include <iostream>
#include <string>
#include "Date.h"
#include "Time.h"

class AirQuality {

public:
    AirQuality();
    AirQuality(Date d, Time t, double temp, double RH, double AH);

    Date GetDate();
    Time GetTime();
    double GetTemp();
    double GetAH();
    double GetRH();

    void setDate(Date d);
    void setTime(Time t);
    void setTemp(double temp);
    void setAH(double AH);
    void setRH(double RH);

    void printAQ();

    Date date;
    Time time;
    double Temp;
    double AHumid;
    double RHumid;

    friend ostream & operator << (ostream & os, const AirQuality & AQ);
    friend istream& operator >> (istream& input, AirQuality& AQ);
};


#endif //FINAL_PROJECT_AIRQUALITY_H
