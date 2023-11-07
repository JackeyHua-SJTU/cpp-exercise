#include "header.hpp"
#include <iostream>

namespace n1 {
int add(int a, int b) {
    return a + b;
}
}

namespace n2 {
int A::add(int a, int b) {
    std::cout << "use add function in class A\n";
    return a + b;
}

int A::sub(int a, int b) {
    std::cout << "use sub function in class A\n";
    return a - b;
}
}