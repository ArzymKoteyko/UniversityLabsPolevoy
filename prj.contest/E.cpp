#include <iostream>

unsigned long long day_prod_func(unsigned long long day, unsigned long long a, unsigned long long k, unsigned long long b, unsigned long long m) {
    return a*day - (day/k)*a + b*day - (day/m)*b;
}

unsigned long long bin_srh_l (unsigned long long work, unsigned long long a, unsigned long long k, unsigned long long b, unsigned long long m) {
    long long l = -1;
    long long r = 9223372036854775806;
    while (r-l>1) {
        unsigned long long w = 0;
        if (day_prod_func((l+r)/2, a, k, b, m) < work) {
            l = (l+r)/2;
        }
        else {
            r = (l+r)/2;
        }
    }
    return r;
}

int main() {
    unsigned long long a, k, b, m, work;
    std::cin >> a >> k >> b >> m >> work;
    std::cout << bin_srh_l(work, a, k, b, m) << std::endl;
}