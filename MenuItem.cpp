//
// Created by Zhuocheng Yu on 4/16/24.
//
#include <iostream>
#include <iomanip>
#include "Vector.h"
#include "AirQuality.h"
#include "Date.h"
#include "Time.h"
#include <list>

using namespace std;

//Get the years in a list that have the month user asked.
list<int> getTheYear(const Vector& airQualityVector, int month){
    int tempYear = 0;
    list<int> yearList;
    for(Vector::Iterator it = airQualityVector.begin(); it != airQualityVector.end(); ++it) {
        AirQuality airQuality = *it;
        if(airQuality.GetDate().GetMonth() == month) {
            if(tempYear != airQuality.GetDate().GetYear()){
                yearList.push_back(airQuality.GetDate().GetYear());
                tempYear = airQuality.GetDate().GetYear();
            }
        }
    }
    return yearList;
}

void displayAverageTemperature(const Vector& airQualityVector, int month, int year) {
    double totalTemp = 0;
    int count = 0;
    for(Vector::Iterator it = airQualityVector.begin(); it != airQualityVector.end(); ++it) {
        AirQuality airQuality = *it;
        if(airQuality.GetDate().GetMonth() == month && airQuality.GetDate().GetYear() == year) {
            totalTemp += airQuality.GetTemp();
            count++;
        }
    }
    double averageTemp = (count > 0) ? totalTemp / count : 0;
    cout << "Average temperature for month " << month << ": " << averageTemp  << " C" << endl;
}



void displayAverageRelativeHumidity(const Vector& airQualityVector, int month, int year) {
    double totalRH = 0;
    int count = 0;

    for(Vector::Iterator it = airQualityVector.begin(); it != airQualityVector.end(); ++it) {
        AirQuality airQuality = *it;
        if(airQuality.GetDate().GetMonth() == month && airQuality.GetDate().GetYear() == year) {
            totalRH += airQuality.GetRH();
            count++;
        }
    }
    double averageRH = (count > 0) ? totalRH / count : 0;
    cout << "Average relative humidity for month " << month << ": " << averageRH  << " %" << endl;
}

void displayAverageAbsoluteHumidity(const Vector& airQualityVector, int month, int year) {
    double totalAH = 0;
    int count = 0;

    for(Vector::Iterator it = airQualityVector.begin(); it != airQualityVector.end(); ++it) {
        AirQuality airQuality = *it;
        if(airQuality.GetDate().GetMonth() == month && airQuality.GetDate().GetYear() == year) {
            totalAH += airQuality.GetAH();
            count++;
        }
    }
    double averageAH = (count > 0) ? totalAH / count : 0;
    cout << "Average absolute humidity for month " << month << ": " << averageAH << endl;
}

void displayTemperatureAndHumidityAtDateTime(const Vector& airQualityVector, const Date& date, const Time& time) {
    bool dateFound = false;

    for (Vector::Iterator it = airQualityVector.begin(); it != airQualityVector.end(); ++it) {
        AirQuality airQuality = *it;
        if (airQuality.GetDate() == date && airQuality.GetTime() == time) {
            cout << "Temperature at " << date << "," << time << ":" << airQuality.GetTemp() << " C "<< endl;
            cout <<"Relative Humidity at " << date << "," << time << ": " <<airQuality.GetRH() << " %" <<endl;
            dateFound = true;
            break;
        }
    }
    if(!dateFound) {
        cout << "No data available for the specific date and time" << endl;
    }
}

void displayHighestTemperature(const Vector& airQualityVector, int month, int year) {
    double highestTemp = -273.15;

    for (Vector::Iterator it = airQualityVector.begin(); it != airQualityVector.end(); ++it) {
        AirQuality airQuality = *it;
        if(airQuality.GetDate().GetMonth() == month && airQuality.GetTemp() > highestTemp && airQuality.GetDate().GetYear() == year) {
            highestTemp = airQuality.GetTemp();
        }
    }
    cout << "Highest temperature in month " << month << ": " << highestTemp << " C" << endl;
}

void displayHighestRelativeHumidity(const Vector& airQualityVector, int month, int year) {
    double highestRH = -1; // Initialize the highest relative humidity to -1

    // Iterate through the airQualityVector to find the highest relative humidity for the given month
    for (Vector::Iterator it = airQualityVector.begin(); it != airQualityVector.end(); ++it) {
        AirQuality airQuality = *it; // Dereference iterator to access AirQuality object
        if (airQuality.GetDate().GetMonth() == month && airQuality.GetRH() > highestRH && airQuality.GetDate().GetYear() == year) {
            highestRH = airQuality.GetRH(); // Update the highest relative humidity
        }
    }

    // Check if any data is available for the given month
    if (highestRH != -1) {
        cout << "Highest relative humidity in month " << month << ": " << highestRH << endl;
    } else {
        cout << "No data available for month " << month << endl;
    }
}

void displayHighestAbsoluteHumidity(const Vector& airQualityVector, int month, int year) {
    double highestAH = -1; // Initialize the highest absolute humidity


    for (Vector::Iterator it = airQualityVector.begin(); it != airQualityVector.end(); ++it) {
        AirQuality airQuality = *it;
        if (airQuality.GetDate().GetMonth() == month && airQuality.GetAH() > highestAH && airQuality.GetDate().GetYear() == year) {
            highestAH = airQuality.GetAH();
        }
    }

    if (highestAH != -1) {
        cout << "Highest absolute humidity in month " << month << ": " << highestAH << endl;
    } else {
        cout << "No data available for month " << month << endl;
    }
}

void displayTemperatureAboveAverage(const Vector& airQualityVector, int month, int year) {
    double totalTemp = 0;
    int count = 0;
    double highestTemp = -273.15; // Absolute zero in Celsius


    for (Vector::Iterator it = airQualityVector.begin(); it != airQualityVector.end(); ++it) {
        AirQuality airQuality = *it;
        if (airQuality.GetDate().GetMonth() == month && airQuality.GetDate().GetYear() == year) {
            totalTemp += airQuality.GetTemp();
            count++;

            if (airQuality.GetTemp() > highestTemp && airQuality.GetDate().GetYear() == year) {
                highestTemp = airQuality.GetTemp();
            }
        }
    }

    double averageTemp = (count > 0) ? totalTemp / count : 0;

    cout << "Dates and times when temperature is higher than average for month " << month << ":" << endl;
    for (Vector::Iterator it = airQualityVector.begin(); it != airQualityVector.end(); ++it) {
        AirQuality airQuality = *it;
        if (airQuality.GetDate().GetMonth() == month && airQuality.GetTemp() > averageTemp && airQuality.GetDate().GetYear() == year) {
            cout << "Date: " << airQuality.GetDate() << ", Time: " << airQuality.GetTime() << ", Temperature: " << airQuality.GetTemp() << endl;
        }
    }

    cout << "Highest temperature in month " << month << ": " << highestTemp << endl;
}

void displayRelativeHumidityAboveAverage(const Vector& airQualityVector, int month, int year) {
    double totalRH = 0;
    int count = 0;
    double highestRH = -1;

    for (Vector::Iterator it = airQualityVector.begin(); it != airQualityVector.end(); ++it) {
        AirQuality airQuality = *it;
        if (airQuality.GetDate().GetMonth() == month && airQuality.GetDate().GetYear() == year) {
            totalRH += airQuality.GetRH();
            count++;

            if (airQuality.GetRH() > highestRH && airQuality.GetDate().GetYear() == year) {
                highestRH = airQuality.GetRH();
            }
        }
    }

    double averageRH = (count > 0) ? totalRH / count : 0;

    cout << "Dates and times when relative humidity is higher than average for month " << month << ":" << endl;
    for (Vector::Iterator it = airQualityVector.begin(); it != airQualityVector.end(); ++it) {
        AirQuality airQuality = *it;
        if (airQuality.GetDate().GetMonth() == month && airQuality.GetRH() > averageRH && airQuality.GetDate().GetYear() == year) {
            cout << "Date: " << airQuality.GetDate() << ", Time: " << airQuality.GetTime() << ", Relative Humidity: " << airQuality.GetRH() << endl;
        }
    }

    cout << "Highest relative humidity in month " << month << ": " << highestRH << endl;
}

void displayAbsoluteHumidityAboveAverage(const Vector& airQualityVector, int month, int year) {
    double totalAH = 0;
    int count = 0;
    double highestAH = -1;

    for (Vector::Iterator it = airQualityVector.begin(); it != airQualityVector.end(); ++it) {
        AirQuality airQuality = *it;
        if (airQuality.GetDate().GetMonth() == month && airQuality.GetDate().GetYear() == year) {
            totalAH += airQuality.GetAH();
            count++;

            if (airQuality.GetAH() > highestAH && airQuality.GetDate().GetYear() == year) {
                highestAH = airQuality.GetAH();
            }
        }
    }

    double averageAH = (count > 0) ? totalAH / count : 0;

    cout << "Dates and times when absolute humidity is higher than average for month " << month << ":" << endl;
    for (Vector::Iterator it = airQualityVector.begin(); it != airQualityVector.end(); ++it) {
        AirQuality airQuality = *it;
        if (airQuality.GetDate().GetMonth() == month && airQuality.GetAH() > averageAH && airQuality.GetDate().GetYear() == year) {
            std::cout << "Date: " << airQuality.GetDate() << ", Time: " << airQuality.GetTime() << ", Absolute Humidity: " << airQuality.GetAH() << std::endl;
        }
    }

    cout << "Highest absolute humidity in month " << month << ": " << highestAH << endl;
}