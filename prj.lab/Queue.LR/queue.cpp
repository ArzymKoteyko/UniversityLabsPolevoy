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


void Queue::insert(const int& val, std::unique_ptr<Queue::Node>& ancestor) {
    std::unique_ptr<Node> new_node = std::unique_ptr<Node>(new Node(val));
    new_node->next_node_.swap(ancestor);
    ancestor.swap(new_node);
}


auto Queue::find_position(const int& val, std::unique_ptr<Node>& node) -> std::unique_ptr<Node>& {
    if (val < node->val_) {
        return node;
    }
    else if (node->next_node_) {
        return find_position(val, node->next_node_);
    }
    else {
        return node->next_node_;
    }
}


void Queue::push(const int& val) {
    if (!Queue::is_empty()) {
        insert(val, find_position(val, head_));
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

