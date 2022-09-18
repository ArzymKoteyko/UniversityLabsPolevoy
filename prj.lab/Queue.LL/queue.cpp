#include "queue.hpp"


Queue::Node::Node(const int& val) {
    val_ = val;
}


Queue::Node::~Node() {
    std::cout << "..~Node  val: " << val_ << " pointer: " << this << std::endl;
}


bool Queue::is_empty() const {
    return !bool(head_);
}


void Queue::insert(const int& val, std::unique_ptr<Queue::Node>& node) {
    if (node->next_node_) {
        Queue::insert(val, node->next_node_);
    }   
    else {
        node->next_node_.reset(new Queue::Node(val));
    }

    if (node->val_ > node->next_node_->val_) {
        std::swap(node->val_, node->next_node_->val_);
    }
}


void Queue::push(const int& val) {
    if (!Queue::is_empty()) {
        Queue::insert(val, head_);
    }
    else {
        head_.reset(new Node(val));
    }
}


void Queue::pop() {
    std::unique_ptr<Node>& temp = head_->next_node_;
    temp.swap(head_);
    temp.reset(nullptr);
}


int Queue::top() const {
    if (!Queue::is_empty()) return head_->val_;
    else return 0;
}

