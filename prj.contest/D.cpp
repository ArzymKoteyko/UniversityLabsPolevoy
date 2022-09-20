#include <algorithm>
#include <iostream>
#include <vector>

int bin_ser_f(int val, std::vector<int>& array) {
    int l = -1;
    int r = array.size();
    while (r-l>1) {
        if (array[(l+r)/2] < val) {
            l = (l+r)/2;
        }
        else {
            r = (l+r)/2;
        }
    }
    return r;
}

int bin_ser_l (int val, std::vector<int>& array) {
    int l = -1;
    int r = array.size();
    while (r-l>1) {
        if (array[(l+r)/2] <= val) {
            l = (l+r)/2;
        }
        else {
            r = (l+r)/2;
        }
    }
    return l;
}

int main() {
    int n, k;
    std::cin >> n;
    std::vector<int> N;
    for (int i=0; i<n; ++i) {
        N.push_back(0);
        std::cin >> N[i];
    }
    std::sort(N.begin(), N.end());
    std::cin >> k;
    for (int i=0; i<k; ++i) {
        int l, r;
        std::cin >> l >> r;
        std::cout << bin_ser_l(r, N) - bin_ser_f(l, N) + 1 << std::endl;
    }   
}