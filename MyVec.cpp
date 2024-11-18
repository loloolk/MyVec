#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <chrono>

template<typename T> class MyVec {
    public:
    int len; // current amount of items
    int capacity; // max amount of items
    int sub_len; // max amount of items in each sub array
    T** data;

    MyVec() {
        len = 0;

        capacity = 100;
        sub_len = 10;

        data = (T**)malloc(sizeof(T*) * ceil((float)capacity / sub_len));
        data[0] = (T*)malloc(sizeof(T) * sub_len);
    }
    MyVec(int cap) {
        len = 0;

        capacity = cap;
        sub_len = 10;

        data = (T**)malloc(sizeof(T*) * ceil((float)capacity / sub_len));
        data[0] = (T*)malloc(sizeof(T) * sub_len);
    }
    ~MyVec() {
        for (int i = 0; i < ceil((float)len / 10); i++) {
            free(data[i]);
        }
        free(data);
    }

    void push(T val) {
        if (len == capacity) {
            std::cout << "Vector is full" << std::endl;
            return;
        }
        else if (len % sub_len == 0 && len != 0) {
            data[(int)floor((float)len / 10)] = (T*)malloc(sizeof(T) * sub_len);
        }

        data[(int)floor((float)len / 10)][len % 10] = val;
        len++;
    }

    T get(int index) {
        if (index < 0 || index >= len) {
            std::cout << "Index out of bounds" << std::endl;
            exit(1);
        }
        return data[(int)floor((float)index / 10)][index % 10];
    }
};
