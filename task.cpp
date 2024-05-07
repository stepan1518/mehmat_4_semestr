#include "libs.h"

Base* CreateData(const char* str, Factory** f) {
    int I = 0, start = 0, x = 0, file_cap = 2, file_size = 0;
    char* file = nullptr, sym = ' ', * data_file = nullptr;

    if (sscanf(str, "%d%n", &I, &x) == 0)
        return nullptr;
    start += x;

    if (I != 0 && I != 1) return nullptr;

    if (start >= (int)strlen(str)) return nullptr;

    while (sym == ' ') {
        if (sscanf(str + start, "%c%n", &sym, &x) == 0)
            return nullptr;
        start += x;
    }

    file = new char[file_cap];
    file[file_size++] = sym;
    file[file_size] = '\0';

    while (sscanf(str + start, "%c%n", &sym, &x) != 0) {
        if ((int)strlen(str) <= start) break;
        if (sym == ' ' || sym == '\n') break;
        start += x;

        if (file_size + 1 >= file_cap) {
            file_cap *= 2;
            data_file = new char[file_cap];
            std::memcpy(data_file, file, file_size);
            delete[] file;
            file = data_file;
            data_file = nullptr;
        }

        file[file_size++] = sym;
        file[file_size] = '\0';
    }

    double* nums = new double[1], num, * data;
    int size = 0, cap = 1;
    while (sscanf(str + start, "%lf%n", &num, &x) == 1) {
        if (size >= cap) {
            cap *= 2;
            data = new double[cap];
            std::memcpy(data, nums, size * sizeof(double));
            delete[] nums;
            nums = data;
        }
        nums[size++] = num;
        start += x;
    }

    Base* res = f[I]->create(nums, size, cap, file);
    
    delete[] nums;

    delete[] file;

    return res;
}

Child0 operator+ (const Base& obj, const Base& other) {
    double* result = new double[obj.length + other.length], * arr1 = obj.arr, * arr2 = other.arr;
    int cur_idx = 0, idx_1 = 0, idx_2 = 0, size = obj.length + other.length;
    Child0 item(0, 0);

    if (size == 0) {
        item = Child0(result, size, size);
        delete[] result;
        return item;
    }

    while (cur_idx < size) {
        if (idx_1 == obj.length) {
            std::swap(arr1, arr2);
            std::swap(idx_1, idx_2);
            break;
        }
        if (idx_2 == other.length) break;
        double com = arr1[idx_1] - arr2[idx_2];
        if (fabs(com) < std::numeric_limits<double>::epsilon() || com < 0) {
            result[idx_1 + idx_2] = arr1[idx_1];
            idx_1++;
        }
        else {
            result[idx_1 + idx_2] = arr2[idx_2];
            idx_2++;
        }
    }
    std::memcpy(result + idx_1 + idx_2, arr1 + idx_1, (size - idx_1 - idx_2) * sizeof(double));

    item = Child0(result, size, size);
    delete[] result;

    return item;
}

Child0 operator--(Base& obj, int) {
    Child0 tmp(obj.arr, obj.length, obj.capacity);
    if (obj.length > 0)
        obj.length--;
    return tmp;
}

Child0 operator++(Base& obj, int) {
    Child0 tmp(obj.arr, obj.length, obj.capacity);
    if (obj.length >= obj.capacity) {
        obj.capacity = 2 * obj.capacity + 1;
        double* temp = new double[obj.capacity];
        std::memcpy(temp, obj.arr, obj.length * sizeof(double));
        delete[] obj.arr;
        obj.arr = temp;
    }
    if (obj.length != 0)
        obj.arr[obj.length] = obj.arr[obj.length - 1];
    obj.length++;
    return tmp;
}

Child1 sumAll(Base** arr, int size) {
    Child0 res(0, 0);
    res = (*arr[0]) + (*arr[1]);

    for (int i = 2; i < size; i++)
        res = res + (*arr[i]);
    return res;
}