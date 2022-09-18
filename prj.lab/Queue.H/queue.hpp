#pragma once
#ifndef QUEUE_H_QUEUE_HPP_7_17_37
#define QUEUE_H_QUEUE_HPP_7_17_37

#include <memory>

class Queue {
    private:
        class Node {
            private:
                int val;
                int child_count;
                std::shared_ptr<Node> parent;
                std::shared_ptr<Node> left;
                std::shared_ptr<Node> right;
                std::shared_ptr<Node> next;
                std::shared_ptr<Node> prev;
            public:
                Node() = default;
                Node(const Node&);
                Node& operator=(const Node&);
                Node(const int&);
                ~Node() = default;
                friend Queue;
                friend std::ostream& operator<<(std::ostream&, const Queue&);
        };
        void buble_up();
        void buble_down();
        std::shared_ptr<Node> head;
        std::shared_ptr<Node> tail;
        std::shared_ptr<Node> front;
    public:
        Queue() = default;
        Queue(const Queue&);
        Queue& operator=(const Queue&);
        ~Queue() = default;
        void push(const int&);
        void pop();
        int top() const;
        friend std::ostream& operator<<(std::ostream&, const Queue&);
};

std::ostream& operator<<(std::ostream&, const Queue&);

#endif