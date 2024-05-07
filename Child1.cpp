#include "libs.h"

Child1::Child1(double* nums, int len, int cap) : Base(nums, len, cap) {}
Child1::Child1(int len, int cap) : Base(len, cap) {}

Child1::Child1(const Base& other) : Base(other) {}
Child1::Child1(Base&& other) : Base(std::move(other)) {}

Child1& Child1::operator= (const Base& other) {
    Base::operator=(other);
    return *this;
}

Child1& Child1::operator= (Base&& other) {
    Base::operator=(std::move(other));
    return *this;
}

Child1::Child1(int len, int cap, char* name) : Base(len, cap) {
    fileName = new char[strlen(name) + 1];
    std::memcpy(fileName, name, strlen(name) + 1);
}

Child1::Child1(double* nums, int len, int cap, char* name) : Base(nums, len, cap) {
    fileName = new char[strlen(name) + 1];
    std::memcpy(fileName, name, strlen(name) + 1);
}

int Child1::output() {
    std::fstream f;
    f.open(fileName, std::ios::app);
    if (!f.is_open()) return 0;

    for (int i = 0; i < length; i++)
        f << arr[i] << "\n";

    f.close();
    return 1;
}

Child1::~Child1() {
    if (fileName != nullptr)
        delete[] fileName;
}