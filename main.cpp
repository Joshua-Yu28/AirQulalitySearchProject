#include <iostream>
#include "Vector.h"
#include <fstream>
#include <sstream>
#include "AirQuality.h"
#include "MenuItem.h"
#include <iomanip>

using namespace std;

//Function to parse data from Excel to AirQuality Object and store in Vector
void parseData(const string& filename, Vector& airQualityVector);
void getYear(Vector& airQualityVector, int month, int year);

int main() {
    Vector airQualityVector;

    parseData("/Users/joshyu/Desktop/FinalProject/Book6.csv", airQualityVector);

    cout << "Number of entries in the Vector: " << airQualityVector.getSize() << endl;

    int choice, month, year;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Display average temperature for a month" << endl;
        cout << "2. Display average relative humidity for a month" << endl;
        cout << "3. Display average absolute humidity for a month" << endl;
        cout << "4. Display temperature and humidity at a specific date and time" << endl;
        cout << "5. Display highest temperature for a month" << endl;
        cout << "6. Display highest relative humidity for a month" << endl;
        cout << "7. Display highest absolute humidity for a month" << endl;
        cout << "8. Display dates and times when temperature is higher than average" << endl;
        cout << "9. Display dates and times when relative humidity is higher than average" << endl;
        cout << "10. Display dates and times when absolute humidity is higher than average" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Process user's choice
        switch (choice) {
            case 1:
                cout << "Enter month: ";
                cin >> month;
                if (getTheYear(airQualityVector, month).size() > 1) {
                    cout << "Enter year( ";
                    for (int specificYear: getTheYear(airQualityVector, month)) {
                        cout << setw(2) << setfill('0') << specificYear << " ";
                    }
                    cout << "): ";
                    cin >> year;
                }
                displayAverageTemperature(airQualityVector, month, year);
                break;
            case 2:
                cout << "Enter month: ";
                cin >> month;
                if(getTheYear(airQualityVector, month).size() > 1){
                    cout << "Enter year( ";
                    for (int specificYear : getTheYear(airQualityVector, month)) {
                        cout << setw(2) << setfill('0') << specificYear << " ";
                    }
                    cout << "): ";
                    cin >> year;
                }
                displayAverageRelativeHumidity(airQualityVector, month, year);
                break;
            case 3:
                cout << "Enter month: ";
                cin >> month;
                if(getTheYear(airQualityVector, month).size() > 1){
                    cout << "Enter year( ";
                    for (int specificYear : getTheYear(airQualityVector, month)) {
                        cout << setw(2) << setfill('0') << specificYear << " ";
                    }
                    cout << "): ";
                    cin >> year;
                }
                displayAverageAbsoluteHumidity(airQualityVector, month, year);
                break;
            case 4: {
                Date date;
                cout << "Enter date(mm/dd/yy) :";
                cin >> date;
                Time time;
                cout << "Enter time(hh:mm:ss) :";
                cin >> time;
                displayTemperatureAndHumidityAtDateTime(airQualityVector, date, time);
                break;
            }
            case 5:
                cout << "Enter month: ";
                cin >> month;
                if(getTheYear(airQualityVector, month).size() > 1){
                    cout << "Enter year( ";
                    for (int specificYear : getTheYear(airQualityVector, month)) {
                        cout << setw(2) << setfill('0') << specificYear << " ";
                    }
                    cout << "): ";
                    cin >> year;
                }
                displayHighestTemperature(airQualityVector, month, year);
                break;
            case 6:
                cout << "Enter month: ";
                cin >> month;
                if(getTheYear(airQualityVector, month).size() > 1){
                    cout << "Enter year( ";
                    for (int specificYear : getTheYear(airQualityVector, month)) {
                        cout << setw(2) << setfill('0') << specificYear << " ";
                    }
                    cout << "): ";
                    cin >> year;
                }
                displayHighestRelativeHumidity(airQualityVector, month, year);
                break;
            case 7:
                cout << "Enter month: ";
                cin >> month;

                displayHighestAbsoluteHumidity(airQualityVector, month, year);
                break;
            case 8:
                cout << "Enter month: ";
                cin >> month;
                if (getTheYear(airQualityVector, month).size() > 1) {
                    cout << "Enter year( ";
                    for (int specificYear: getTheYear(airQualityVector, month)) {
                        cout << setw(2) << setfill('0') << specificYear << " ";
                    }
                    cout << "): ";
                    cin >> year;
                }
                displayTemperatureAboveAverage(airQualityVector, month, year);
                break;
            case 9:
                cout << "Enter month: ";
                cin >> month;
                if (getTheYear(airQualityVector, month).size() > 1) {
                    cout << "Enter year( ";
                    for (int specificYear: getTheYear(airQualityVector, month)) {
                        cout << setw(2) << setfill('0') << specificYear << " ";
                    }
                    cout << "): ";
                    cin >> year;
                }
                displayRelativeHumidityAboveAverage(airQualityVector, month, year);
                break;
            case 10:
                cout << "Enter month: ";
                cin >> month;
                if (getTheYear(airQualityVector, month).size() > 1) {
                    cout << "Enter year( ";
                    for (int specificYear: getTheYear(airQualityVector, month)) {
                        cout << setw(2) << setfill('0') << specificYear << " ";
                    }
                    cout << "): ";
                    cin >> year;
                }
                displayAbsoluteHumidityAboveAverage(airQualityVector, month, year);
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);
    return 0;
}

// Function to parse data from the file
void parseData(const string& filename, Vector& airQualityVector) {
    ifstream file(filename);
    if (!file.is_open()){
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    file.ignore(500,'\n');

    string line;
    while (getline(file, line)){
        // Check if the line is empty or contains only whitespace
        if (line.find_first_not_of(' ') == string::npos) {
            // Skip empty line
            continue;
        }

        istringstream iss(line);
        AirQuality airQuality;

        string dateString, timeString;
        getline(iss, dateString,',');
        getline(iss, timeString,',');

        int month = stoi(dateString.substr(0, dateString.find_first_of('/')));
        int day = stoi(dateString.substr(dateString.find_first_of('/') + 1, dateString.find_last_of('/') - dateString.find_first_of('/') - 1));
        int year = stoi(dateString.substr(dateString.find_last_of('/') + 1));

        int hour = stoi(timeString.substr(0, 2));
        int minute = stoi(timeString.substr(3, 2));
        int second =stoi(timeString.substr(6,2));

        // Skip unwanted columns
        for (int i = 0; i < 10; ++i) {
            string temp;
            getline(iss, temp, ',');
        }

        // Read temperature, AHumidity, and RHumidity as strings
        string tempStr, AHumidStr, RHumidStr;
        getline(iss, tempStr, ',');
        getline(iss, RHumidStr, ',');
        getline(iss, AHumidStr);

        // Convert strings to appropriate data types
        double temp = stod(tempStr);
        double RHumid = stod(RHumidStr);
        double AHumid = stod(AHumidStr);

        // Create Date and Time objects
        Date date(month, day, year);
        Time time(hour, minute, second);

        // Populate AirQuality class
        airQuality.date = date;
        airQuality.time = time;
        airQuality.Temp = temp;
        airQuality.RHumid = RHumid;
        airQuality.AHumid = AHumid;

        airQualityVector.push_back(airQuality);
    }

    file.close();
}




