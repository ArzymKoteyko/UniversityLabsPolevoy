#include <iostream>
#include "queue.hpp"

int main() {

    Queue q;
    q.push(-1);
    for (int i=0; i<10000; i++) {
        q.push(i%50);
    }
    for (int i=0; i<10000; i++) {
        q.pop();
    }
    return 0;
}   