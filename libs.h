#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>
#include <limits>
#include <cmath>

class Base {
public:
    double* arr;
    int length;
    int capacity;

public:
    Base(int len, int cap);

    Base(double* nums, int len, int cap);

    Base(const Base& other);

    Base(Base&& other);

    virtual ~Base();

    Base& operator=(const Base& other);

    Base& operator=(Base&& other);

    double& operator[](int index);

    Base& operator++();

    Base& operator--();

    int len();

    virtual int output() = 0;
};

class Child0 : public Base {
private:
    char* fileName = nullptr;

public:
    Child0(double* nums, int len, int cap);

    Child0(int len, int cap);

    Child0(const Base& other);

    Child0(Base&& other);

    Child0& operator= (const Base& other);

    Child0& operator= (Base&& other);

    Child0(int len, int cap, char* name);

    Child0(double* nums, int len, int cap, char* name);

    int output() override;

    ~Child0();
};

class Child1 : public Base {
private:
    char* fileName = nullptr;

public:
    Child1(double* nums, int len, int cap);

    Child1(int len, int cap);

    Child1(const Base& other);

    Child1(Base&& other);

    Child1& operator= (const Base& other);

    Child1& operator= (Base&& other);

    Child1(int len, int cap, char* name);

    Child1(double* nums, int len, int cap, char* name);

    int output() override;

    ~Child1();
};

class Factory {
public:
	virtual Base* create(double*, int, int, char*) = 0;
	virtual ~Factory() {};
};

class Factory_Child0 : public Factory {
	Base* create(double*, int, int, char*) override;
};

class Factory_Child1 : public Factory {
	Base* create(double*, int, int, char*) override;
};

Base* CreateData(const char* str, Factory** f);

Child0 operator+ (const Base& obj, const Base& other);

Child0 operator--(Base& obj, int);

Child0 operator++(Base& obj, int);

Child1 sumAll(Base** arr, int size);