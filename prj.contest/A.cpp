#include <cmath>
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << std::ceil(std::log2(n)) << std::endl;
    return 0;
}