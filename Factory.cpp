#include "libs.h"

Base* Factory_Child0::create(double* nums, int len, int cap, char* name) {
    return new Child0(nums, len, cap, name);
}

Base* Factory_Child1::create(double* nums, int len, int cap, char* name) {
    return new Child1(nums, len, cap, name);
}