#include <iostream>
#include <vector>
#include <cmath>
#include <string>

void sift_up(std::vector<int>& heap, int i) {
    int parent = (int)std::floor((i-1)/2);
		if(i > 0 && heap[parent] > heap[i]) {
			int temp = heap[i];
			heap[i] = heap[parent];
			heap[parent] = temp;
			sift_up(heap, parent);
		}
}

void sift_down(std::vector<int>& heap, int i) {
    int leftChild = 2*i + 1;
		int rightChild = 2*i + 2;
		int largerChild;
		if(rightChild < heap.size() && heap[rightChild] < heap[leftChild]) {
			largerChild = rightChild;
		} else {
			largerChild = leftChild;
		}
		if(largerChild < heap.size() && heap[largerChild] < heap[i]) {
			int temp = heap[i];
			heap[i] = heap[largerChild];
			heap[largerChild] = temp;
			sift_down(heap, largerChild);
		}
}

void add(std::vector<int>& heap, int val) {
    heap.push_back(val);
    sift_up(heap, heap.size()-1);
}

int extract(std::vector<int>& heap) {
    int res = heap[0];
    std::swap(heap[0], heap[heap.size()-1]);
    heap.pop_back();
    sift_down(heap, 0);
    return res;
}

int main() {
    std::vector<int> heap;
    int n;
    std::cin >> n;
    for (int i=0; i<n; ++i) {
        int val;
        std::cin >> val;
        add(heap, val);
    }
    for (int i=0; i<n; ++i) {
        std::cout << extract(heap) << " ";
    }
    std::cout << std::endl;
}