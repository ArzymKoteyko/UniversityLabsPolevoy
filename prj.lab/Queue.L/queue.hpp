#pragma once
#ifndef QUEUE_L_QUEUE_HPP_7_23_24
#define QUEUE_L_QUEUE_HPP_7_23_24

#include <memory>

class Queue {
    private:
        class Node {
            private:
                std::unique_ptr<Node> next;
                int val;
            public:
                Node() = default;
                Node(const Node&);
                Node& operator=(const Node&);
                ~Node() = default;
        };
    public:
        std::unique_ptr<Node> head;
        Queue() = default;
        Queue(const Queue&);
        Queue& operator=(const Queue&);
        ~Queue() = default;
        void push(const int&);
        void pop();
        int top();
};

#endif