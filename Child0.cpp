#include "libs.h"

Child0::Child0(double* nums, int len, int cap) : Base(nums, len, cap) {}
Child0::Child0(int len, int cap) : Base(len, cap) {}

Child0::Child0(const Base& other) : Base(other) {}
Child0::Child0(Base&& other) : Base(std::move(other)) {}

Child0& Child0::operator= (const Base& other) {
    Base::operator=(other);
    return *this;
}

Child0& Child0::operator= (Base&& other) {
    Base::operator=(std::move(other));
    return *this;
}

Child0::Child0(int len, int cap, char* name) : Base(len, cap) {
    fileName = new char[strlen(name) + 1];
    std::memcpy(fileName, name, strlen(name) + 1);
}

Child0::Child0(double* nums, int len, int cap, char* name) : Base(nums, len, cap) {
    fileName = new char[strlen(name) + 1];
    std::memcpy(fileName, name, strlen(name) + 1);
}

int Child0::output() {
    std::fstream f;
    f.open(fileName, std::ios::app);
    if (!f.is_open()) return 0;

    for (int i = 0; i < length; i++)
        f << arr[i] << " ";

    f.close();
    return 1;
}

Child0::~Child0() {
    if (fileName != nullptr)
        delete[] fileName;
}