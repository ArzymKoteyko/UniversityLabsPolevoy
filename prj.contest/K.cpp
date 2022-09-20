#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>

void sift_up(std::vector<long long>& heap, long long i) {
    long long parent = (long long)std::floor((i-1)/2);
		if(i > 0 && heap[parent] > heap[i]) {
			long long temp = heap[i];
			heap[i] = heap[parent];
			heap[parent] = temp;
			sift_up(heap, parent);
		}
}

void sift_down(std::vector<long long>& heap, long long i) {
    long long leftChild = 2*i + 1;
		long long rightChild = 2*i + 2;
		long long largerChild;
		if(rightChild < heap.size() && heap[rightChild] < heap[leftChild]) {
			largerChild = rightChild;
		} else {
			largerChild = leftChild;
		}
		if(largerChild < heap.size() && heap[largerChild] < heap[i]) {
			long long temp = heap[i];
			heap[i] = heap[largerChild];
			heap[largerChild] = temp;
			sift_down(heap, largerChild);
		}
}

void add(std::vector<long long>& heap, long long val) {
    heap.push_back(val);
    sift_up(heap, heap.size()-1);
}

long long extract(std::vector<long long>& heap) {
    long long res = heap[0];
    std::swap(heap[0], heap[heap.size()-1]);
    heap.pop_back();
    sift_down(heap, 0);
    return res;
}

int main() {
    std::vector<long long> heap;
    long long n;
    std::cin >> n;
    for (long long i=0; i<n; ++i) {
        long long val;
        std::cin >> val;
        add(heap, val);
    }
    long double prcnt = 0.05;
    long double price = 0;
    while (heap.size()!=1) {
        long long a = extract(heap);
        long long b = extract(heap);
        long long sum = a + b;
        price += (long double)sum * prcnt;
        add(heap, sum);
    }
    std::cout << std::fixed << std::setprecision(2) << price << std::endl;
}