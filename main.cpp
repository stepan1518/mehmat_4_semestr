#include "libs.h"

int main() {
    int capacity = 1, size = 0, str_cap = 2, str_size = 0;
    Base** arr = new Base * [capacity], ** data = nullptr, * base;
    FILE* file = fopen("input.txt", "r");
    char* str = new char[str_cap], * str_data = nullptr, sym;
    Factory* f[2] = { new Factory_Child0, new Factory_Child1};

    memset(str, 0, str_cap);

    if (file == NULL) {
        delete[] str;
        delete[] arr;
        delete f[0];
        delete f[1];
        printf("File does not exist");
        return -1;
    }

    while (sym != EOF) {
        sym = fgetc(file);

        if (str_size + 1 >= str_cap) {
            str_cap *= 2;
            str_data = new char[str_cap];
            std::memset(str_data, 0, str_cap);
            std::memcpy(str_data, str, str_size + 1);
            delete[] str;
            str = str_data;
            str_data = nullptr;
        }

        if (sym != '\n' && sym != EOF) {
            str[str_size++] = sym;
            str[str_size] = '\0';
            continue;
        }

        if (size >= capacity) {
            capacity *= 2;
            data = new Base * [capacity];
            std::memcpy(data, arr, size * sizeof(Base*));
            delete[] arr;
            arr = data;
            data = nullptr;
        }

        base = CreateData(str, f);
        if (base != nullptr) arr[size++] = base;

        str_size = 0;
        str[0] = '\0';
    }

    fclose(file);
    delete[] str;
    delete f[0];
    delete f[1];

    Base* obj1 = arr[0], * obj2 = arr[1];
    ++(*obj1);
    ++(*obj1);
    (*obj1)--;
    (*obj1)--;
    (*obj2)++;
    (*obj2)++;
    --(*obj2);
    --(*obj2);

    for (int i = 0; i < size; i++)
        arr[i]->output();

    Child1 res = sumAll(arr, size);

    for (int i = 0; i < res.len(); i++)
        std::cout << res[i] << " ";
    std::cout << "\n";

    res = std::move(*arr[size - 1]);
    for (int i = size - 1; i > 0; i--)
        (*arr[i]) = std::move(*arr[i - 1]);
    (*arr[0]) = std::move(res);

    res = sumAll(arr, size);

    for (int i = 0; i < res.len(); i++)
        std::cout << res[i] << " ";

    for (int i = 0; i < size; i++)
        delete arr[i];
    delete[] arr;

    return 0;
}
