#include "queue.hpp"
#include <algorithm>
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Queue& queue) {
    std::cout << "OK1" << " ";
    std::shared_ptr<Queue::Node> cursor = queue.head;
    std::cout << "OK2" << " ";
    while(cursor) {
        std::cout << "OK3" << " ";
        os << cursor->val << " ";
        std::cout << "OK4" << " ";
        cursor = cursor->next;
        std::cout << "OK5" << " ";
    }
    std::cout << "OK6" << " ";
    return os;
}

Queue::Node::Node(const int& val) {
    this->val = val;
    child_count = 0;
}

void Queue::push(const int& val) {
    if (front) {
        const bool is_right = (front->child_count == 1);
        std::shared_ptr<Queue::Node>& child = is_right ? front->right : front->left;
        child.reset(new Node(val));
        child->prev = tail;
        child->parent = front;
        tail->next = child;
        tail = child;
        front->child_count++;
        if (is_right) front = front->next;
        buble_up();
    }
    else {
        front = std::shared_ptr<Queue::Node>(new Node(val));
        head = front;
        tail = front;
    }
}

void Queue::buble_up() {
    std::shared_ptr<Queue::Node> cursor = tail;
    while (cursor->parent) {
        if (cursor->val > cursor->parent->val) {
            std::swap(cursor->val, cursor->parent->val);
            cursor = cursor->parent;
        }
        else break;
    }
}

void Queue::pop() {
    //std::cout << "q" << head->val << "  " << tail->val << "  " << front->val << std::endl;
    head->val = tail->val;
    front->child_count--;
    if (front->child_count==1) {
        return;
    }
    else {
        front = front->prev;
        return;
    }
    if (tail->prev) {
        tail = tail->prev;
        tail->next->parent.reset();
        tail->next->prev.reset();
        tail->next.reset();
        buble_down();
    }
    else {
        tail->next.reset();
        tail.reset();
        head.reset();
        front.reset();
    }
}

void Queue::buble_down() {
    std::shared_ptr<Queue::Node> cursor = head;
    while(cursor->child_count != 0) {  
        std::shared_ptr<Queue::Node> largest = cursor;
        //std::cout << *this << " | " << cursor->child_count << std::endl;
        /*
        if (cursor->left->val > largest->val) {
            largest = cursor->left;
        }
        /*
        if (cursor->right->val > largest->val) {
            largest = cursor->right;
        }
        */
        largest = cursor->left ? (cursor->left->val > largest->val) ? cursor->left : largest : largest;
        largest = cursor->right ? cursor->right->val > largest->val ? cursor->right : largest : largest;
        std::swap(cursor->val, largest->val);
        if (cursor == largest) {
            break;
        }
        else {
            cursor = largest;
        }
        
    }
}
