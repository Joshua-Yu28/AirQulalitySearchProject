#ifndef FINAL_PROJECT_VECTOR_H
#define FINAL_PROJECT_VECTOR_H
#include "AirQuality.h"

class Vector {
private:
    AirQuality** array;
    int capacity;
    int size;

public:
    class Iterator {
    private:
        AirQuality** ptr;
    public:
        Iterator(AirQuality** p) : ptr(p) {}
        Iterator& operator++() { ptr++; return *this; }
        Iterator operator++(int) { Iterator temp = *this; ptr++; return temp; }
        AirQuality& operator*() { return **ptr; }
        bool operator==(const Iterator& other) const { return ptr == other.ptr; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
    };

    Vector();
    ~Vector();

    void push_back(const AirQuality& airQuality);
    Iterator begin() const;
    Iterator end() const;
    int getSize() const;
};


#endif //FINAL_PROJECT_VECTOR_H
