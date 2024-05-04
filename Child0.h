class Child0 : public Base {
private:
    char* fileName = nullptr;

public:
    Child0(double* nums, int len, int cap) : Base(nums, len, cap) {}
    Child0(int len, int cap) : Base(len, cap) {}

    Child0& operator= (const Base& other) {
        Base::operator=(other);
        return *this;
    }

    Child0(int len, int cap, char* name) : Base(len, cap) {
        fileName = new char[strlen(name) + 1];
        std::memcpy(fileName, name, strlen(name) + 1);
    }

    Child0(double* nums, int len, int cap, char* name) : Base(nums, len, cap) {
        fileName = new char[strlen(name) + 1];
        std::memcpy(fileName, name, strlen(name) + 1);
    }

    int output() override {
        std::fstream f;
        f.open(fileName, std::ios::app);
        if (!f.is_open()) return 0;

        for (int i = 0; i < length; i++)
            f << arr[i] << " ";

        f.close();
        return 1;
    }

    ~Child0() {
        if (fileName != nullptr)
            delete[] fileName;
    }
};