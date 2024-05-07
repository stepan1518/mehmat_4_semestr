#include "libs.h"

Base::Base(int len, int cap) : length(len), capacity(cap) {
    arr = new double[capacity];
}

Base::Base(double* nums, int len, int cap) : length(len), capacity(cap) {
    arr = new double[capacity];
    std::memcpy(arr, nums, len * sizeof(double));
}

Base::Base(const Base& other) : length(other.length), capacity(other.capacity) {
    arr = new double[capacity];
    std::memcpy(arr, other.arr, length * sizeof(double));
}

Base::Base(Base&& other) : arr(other.arr), length(other.length), capacity(other.capacity) {
    other.arr = nullptr;
    other.length = 0;
    other.capacity = 0;
}

Base::~Base() {
    delete[] arr;
}

Base& Base::operator=(const Base& other) {
    if (this != &other) {
        delete[] arr;
        length = other.length;
        capacity = other.capacity;
        arr = new double[capacity];
        std::memcpy(arr, other.arr, length * sizeof(double));
    }
    return *this;
}

Base& Base::operator=(Base&& other) {
    if (this != &other) {
        delete[] arr;
        arr = other.arr;
        length = other.length;
        capacity = other.capacity;
        other.arr = nullptr;
        other.length = 0;
        other.capacity = 0;
    }
    return *this;
}

double& Base::operator[](int index) {
    return arr[index];
}

Base& Base::operator++() {
    if (length >= capacity) {
        capacity = 2 * capacity + 1;
        double* temp = new double[capacity];
        std::memcpy(temp + 1, arr, length * sizeof(double));
        delete[] arr;
        arr = temp;
    }
    else std::memcpy(arr + 1, arr, length * sizeof(double));
    if (length != 0)
        arr[0] = arr[1];
    length++;
    return *this;
}

Base& Base::operator--() {
    if (length > 0) {
        for (int i = 1; i < length; i++)
            arr[i - 1] = arr[i];
        length--;
    }
    return *this;
}

int Base::len() { return length; }