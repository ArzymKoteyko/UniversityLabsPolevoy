#include <iostream>
#include "queue.hpp"

int main() {

    Queue q;
    q.push(-1);
    q.push(10);
    q.push(4);
    q.push(6);
    q.push(73);
    q.push(-23);
    q.push(-3);
    q.push(0);
    std::cout << q << std::endl;
    return 0;
}    