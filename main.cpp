#include <iostream>
#include "MyVec.cpp"

int main() {

    MyVec<int> vec = MyVec<int>(1000);
    for (int i = 0; i < 998; i++) {
        vec.push(i);
    }
    std::cout << vec.get(999) << std::endl;

    return 0;
}