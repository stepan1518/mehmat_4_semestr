class Base {
public:
    double* arr;
    int length;
    int capacity;

public:
    Base(int len, int cap) : length(len), capacity(cap) {
        arr = new double[capacity];
    }

    Base(double* nums, int len, int cap) : length(len), capacity(cap) {
        arr = new double[capacity];
        std::memcpy(arr, nums, len * sizeof(double));
    }

    Base(const Base& other) : length(other.length), capacity(other.capacity) {
        arr = new double[capacity];
        std::memcpy(arr, other.arr, length * sizeof(double));
    }

    Base(Base&& other) : arr(other.arr), length(other.length), capacity(other.capacity) {
        other.arr = nullptr;
        other.length = 0;
        other.capacity = 0;
    }

    virtual ~Base() {
        delete[] arr;
    }

    Base& operator=(const Base& other) {
        if (this != &other) {
            delete[] arr;
            length = other.length;
            capacity = other.capacity;
            arr = new double[capacity];
            std::memcpy(arr, other.arr, length * sizeof(double));
        }
        return *this;
    }

    Base& operator=(Base&& other) {
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

    double& operator[](int index) {
        return arr[index];
    }

    Base& operator++() {
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

    Base& operator--() {
        if (length > 0) {
            for (int i = 1; i < length; i++)
                arr[i - 1] = arr[i];
            length--;
        }
        return *this;
    }

    int len() { return length; }

    virtual int output() = 0;
};