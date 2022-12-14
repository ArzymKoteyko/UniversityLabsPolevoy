#include "queue.hpp"


QueueP::Node::Node(const int& val) {
    val_ = val;
}


/*
QueueP::Node::~Node() {
    std::cout << "..~Node  val: " << val_ << " pointer: " << this << std::endl;
}*/


QueueP::QueueP(const QueueP& queue) noexcept {
    if (!queue.is_empty()) {
        const std::unique_ptr<Node>* cursor = &(queue.head_);
        do {
            this->push((*cursor)->val_);
            cursor = &((*cursor)->next_node_);
        }
        while((*cursor));
    }
}

/*
QueueP& QueueP::operator=(const QueueP& queue) {
    return QueueP(queue);
}
*/


QueueP::QueueP(QueueP&& queue) noexcept {
    while(!queue.is_empty()) {
        this->push(queue.top());
        queue.pop();
    }
}

bool QueueP::is_empty() const noexcept {
    return !bool(head_);
}


void QueueP::insert(const int& val, std::unique_ptr<QueueP::Node>& ancestor) noexcept {
    std::unique_ptr<Node> new_node = std::unique_ptr<Node>(new Node(val));
    new_node->next_node_.swap(ancestor);
    ancestor.swap(new_node);
}


auto QueueP::find_position(const int& val, std::unique_ptr<Node>& node) const noexcept -> std::unique_ptr<Node>& {
    std::unique_ptr<std::unique_ptr<Node>> cursor = std::unique_ptr<std::unique_ptr<Node>>(&node);
    while ((*cursor)->next_node_) {
        if (val <= (*cursor)->val_) {
            std::unique_ptr<Node>& answer = (*cursor);
            cursor.release();
            return answer;
        }
        std::unique_ptr<std::unique_ptr<Node>> next_cursor = std::unique_ptr<std::unique_ptr<Node>>(&(*cursor)->next_node_);
        cursor.swap(next_cursor);
        next_cursor.release();
    }
    if (val <= (*cursor)->val_) {
        std::unique_ptr<Node>& answer = (*cursor);
        cursor.release();
        return answer;
    }
    else {
        std::unique_ptr<Node>& answer = (*cursor)->next_node_;
        cursor.release();
        return answer;  
    }
}


void QueueP::push(const int& val) noexcept {
    if (!QueueP::is_empty()) {
        insert(val, find_position(val, head_));
    }
    else {
        head_.reset(new Node(val));
    }
}


void QueueP::pop() {
    if (!is_empty()) {
        std::unique_ptr<Node>& temp = head_->next_node_;
        temp.swap(head_);
        temp.reset(nullptr);
    }
    else throw std::out_of_range("Queue is empty");
}


int QueueP::top() const {
    if (!is_empty()) return head_->val_;
    else throw std::out_of_range("Queue is empty");
}

