#include "Vector.h"

Vector::Vector() : array(nullptr), capacity(0), size(0) {}

Vector::~Vector() {
    if (array != nullptr) {
        for (int i = 0; i < size; ++i) {
            delete array[i];
        }
        delete[] array;
    }
}

void Vector::push_back(const AirQuality& airQuality) {
    if (size == capacity) {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        AirQuality** newArray = new AirQuality*[newCapacity];
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }
    array[size++] = new AirQuality(airQuality);
}

Vector::Iterator Vector::begin() const{
    return Iterator(array);
}

Vector::Iterator Vector::end() const{
    return Iterator(array + size);
}

int Vector::getSize() const {
    return size;
}