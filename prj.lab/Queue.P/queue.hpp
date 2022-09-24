#pragma once
#ifndef QUEUE_L_QUEUE_HPP_7_23_24
#define QUEUE_L_QUEUE_HPP_7_23_24

#include <memory>
#include <iostream>


class QueueP {
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
                ~Node() = default;
            friend QueueP;
        };
        std::unique_ptr<Node> head_;
        void insert(const int&, std::unique_ptr<Node>&);
        std::unique_ptr<Node>& find_position(const int& val, std::unique_ptr<Node>&);  
    public:
        QueueP() = default;
        QueueP(const QueueP&);
        QueueP(QueueP&&);
        QueueP& operator=(const QueueP&);
        QueueP&& operator=(QueueP&&);
        ~QueueP() = default;
        void push(const int&);
        void pop();
        int top() const;
        bool is_empty() const;
};


#endif