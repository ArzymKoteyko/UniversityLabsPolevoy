#include <iostream>
#include <vector>

void is_in_array(const int& val, const std::vector<int>& array) {
    int l = -1;
    int r = array.size() + 1;
    while (r - l > 1) {
        int s = (l+r)/2;
        if (array[(l+r)/2] < val) {
            l = (l+r)/2;
        }
        else {
            r = (l+r)/2;
        }
    }
    if (array[r] == val) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> N, K;
    for (int i=0; i<n; ++i) {
        N.push_back(0);
        std::cin >> N[i];
    }
    for (int i=0; i<k; ++i) {
        K.push_back(0);
        std::cin >> K[i];
    }
    for (int i=0; i<k; i++) {
        is_in_array(K[i], N);
    }
}