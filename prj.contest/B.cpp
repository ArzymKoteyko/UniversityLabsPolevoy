#include <iostream>
#include <cmath>
#include <iomanip>

long double polyn(long double x, int a, int b, int c, int d) {
    return ((long double)a*std::pow(x,3) + (long double)b*std::pow(x,2) + (long double)c*x + (long double)d);
}

long double bin_ans(int a, int b, int c, int d, long double lb = -1000, long double ub = 1000, long double E = 0.00000001) {
    long double l = lb - 1;
    long double r = ub + 1;
    if (a > 0) {
        while (r-l > E) {
            if (polyn((l+r)/2, a, b, c, d) > 0) {
                r = (l+r)/2;
            }
            else l = (l+r)/2;
        }
        return r;
    }
    else {
        while (r-l > E) {
            if (polyn((l+r)/2, a, b, c, d) > 0) {
                l = (l+r)/2;
            }
            else r = (l+r)/2;
        }
        return r;
    }
}

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << std::setprecision(10) << bin_ans(a, b, c, d); 
}