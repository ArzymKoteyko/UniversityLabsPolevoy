#include <iostream>
#include <ctime>
#include <chrono>
#include "queue.hpp"

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::system_clock;

int main() {
    

    Queue q;
    /*
    auto t = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    
    q.push(-1);
    for (int i=0; i<100000; i++) {
        q.push(i%50);
    }
    for (int i=0; i<100000; i++) {
        q.pop();
    }
    t = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() - t;
    std::cout << t << std::endl << std::endl;
    */

    q.push(-1);
    q.push(10);
    q.push(4);
    q.push(6);
    q.push(73);
    q.push(-23);
    q.push(-3);
    q.push(0);
    //std::cout << q << std::endl;
    q.pop();
    //std::cout << q << std::endl;
    q.pop();
    //std::cout << q << std::endl;
    q.pop();
    //std::cout << q << std::endl;
    q.pop();
    //std::cout << q << std::endl;
    q.pop();
    //std::cout << q << std::endl;
    q.pop();
    //std::cout << q << std::endl;
    q.pop();
    std::cout << "OK ";
    std::cout << q << std::endl;
    std::cout << "OK";
    q.pop();
    std::cout << q << std::endl;
    
    return 0;
}   