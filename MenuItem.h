//
// Created by Zhuocheng Yu on 4/16/24.
//

#ifndef FINAL_PROJECT_MENUITEM_H
#define FINAL_PROJECT_MENUITEM_H

#include "Vector.h"
#include <list>

list<int> getTheYear(const Vector& airQualityVector, int month);
void displayAverageTemperature(const Vector& airQualityVector, int month, int year);
void displayAverageRelativeHumidity(const Vector& airQualityVector, int month, int year);
void displayAverageAbsoluteHumidity(const Vector& airQualityVector, int month, int year);
void displayTemperatureAndHumidityAtDateTime(const Vector& airQualityVector, const Date& date, const Time& time);
void displayHighestTemperature(const Vector& airQualityVector, int month, int year);
void displayHighestRelativeHumidity(const Vector& airQualityVector, int month, int year);
void displayHighestAbsoluteHumidity(const Vector& airQualityVector, int month, int year);
void displayTemperatureAboveAverage(const Vector& airQualityVector, int month, int year);
void displayRelativeHumidityAboveAverage(const Vector& airQualityVector, int month, int year);
void displayAbsoluteHumidityAboveAverage(const Vector& airQualityVector, int month, int year);



#endif //FINAL_PROJECT_MENUITEM_H
