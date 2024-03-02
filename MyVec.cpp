#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <chrono>

template<typename T> class MyVec {
    public:
    T* data[10];
    int len;
    int capacity; // max amount of items
    int sub_len; // max amount of items in each sub array

    MyVec() {
        len = 0;
        capacity = 10;
        sub_len = 10;
        data[0] = (T*)malloc(sizeof(T) * sub_len);
    }
    ~MyVec() {
        for (int i = 0; i < ceil((float)len / 10); i++) {
            free(data[i]);
        }
    }

    void push(T val) {
        if (len == capacity) {
            if (capacity == 100) {
                std::cout << "Vector is full" << std::endl;
                return;
            }
            data[(int)ceil((float)len / 10)] = (T*) malloc(sizeof(T) * 10);
            capacity += 10;
        }

        data[(int)floor((float)len / 10)][len % 10] = val;
        len++;
    }

    T get(int index) {
        if (index >= len) {
            std::cout << "Index out of bounds" << std::endl;
            exit(1);
        }
        return data[(int)floor((float)index / 10)][index % 10];
    }
};
