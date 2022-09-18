#include <iostream>
#include "queue.hpp"
#include <queue>

int main() {

    Queue q;
    q.push(5);
    std::cout << q.top() << std::endl;
    q.push(6);
    std::cout << q.top() << std::endl;
    q.push(1);
    std::cout << q.top() << std::endl;
    q.push(4);
    std::cout << q.top() << std::endl;
    q.push(0);
    std::cout << q.top() << std::endl;
    q.push(7);
    std::cout << q.top() << std::endl;
    q.push(6);
    std::cout << q.top() << std::endl;
    q.push(3);
    std::cout << q.top() << std::endl;
    q.push(0);
    std::cout << q.top() << std::endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(1);
    std::cout << q.top() << std::endl;

    std::queue<int> check;
    std::cout << "OK" << std::endl;

    std::cout << check.front() << std::endl;

    

    return 0;
}    