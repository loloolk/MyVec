#include <iostream>
#include <omp.h>

int main() {
    for (int i = 0; i < 10000; i++) {
        std::cout << i << std::endl;
    }
    return 0;
}