#include "AirQuality.h"
#include <iomanip>

using namespace std;

//Default constructor
AirQuality::AirQuality() {}

AirQuality::AirQuality(Date d, Time t, double temp, double RH, double AH) {
    date = d;
    time = t;
    Temp = temp;
    RHumid = RH;
    AHumid = AH;
}

Date AirQuality::GetDate() {return date;}
Time AirQuality::GetTime() {return time;}
double AirQuality::GetTemp() {return Temp;}
double AirQuality::GetAH() {return AHumid;}
double AirQuality::GetRH() {return RHumid;}

void AirQuality::setDate(Date d) {date = d;}
void AirQuality::setTime(Time t){time = t;}
void AirQuality::setTemp(double temp) {Temp = temp;}
void AirQuality::setAH(double AH) {AHumid = AH;}
void AirQuality::setRH(double RH) {RHumid = RH;}

void AirQuality::printAQ(){
    cout << date << " "<< time << " "<< "Temperature: " << Temp << " "
    << "Relative Humidity: " << RHumid << " " << "Absolute Humidity: " << AHumid << " "<< endl;
}

istream& operator>>(istream& input, AirQuality& AQ) {
    input >> AQ.date >> AQ.time >> AQ.Temp >> AQ.RHumid >> AQ.AHumid;
    return input;
}

ostream& operator<<(ostream& os, const AirQuality& AQ) {
    os << AQ.date << ", " << AQ.time << ", " << "Temperature: " << AQ.Temp << " C"
    << ", " << "Absolute Humidity: " << AQ.RHumid << ", "
    << "Relative Humidity: " << AQ.AHumid << "%" << endl;
    return os;
}
