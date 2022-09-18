#pragma once
#ifndef QUEUE_L_QUEUE_HPP_7_23_24
#define QUEUE_L_QUEUE_HPP_7_23_24

#include <memory>
#include <iostream>


class Queue {
    private:
        class Node {
            private:
                std::unique_ptr<Node> next_node_;
                int val_;
            public:
                Node() = default;
                Node(const Node&);
                Node(const int&);
                Node& operator=(const Node&);
                ~Node();
            friend Queue;
        };
        std::unique_ptr<Node> head_;
        void insert(const int&, std::unique_ptr<Node>&); 
    public:
        Queue() = default;
        Queue(const Queue&);
        Queue& operator=(const Queue&);
        ~Queue() = default;
        void push(const int&);
        void pop();
        int top() const;
        bool is_empty() const;
};


#endif