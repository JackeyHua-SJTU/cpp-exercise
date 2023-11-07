#include <iostream>
#include "header.hpp"
#include <utility>

int main(int argc, char **argv) {
    std::cout << n1::add(1, 2) << std::endl;
    n2::A a;
    std::cout << a.add(1, 2) << std::endl;
    std::cout << a.sub(1, 2) << std::endl;

    // make_pair does not need to specify the type of the pair
    auto i = std::make_pair(1, 2);
    std::cout << i.first << " " << i.second << std::endl;
    return 0;
}