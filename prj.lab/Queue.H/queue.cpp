#include "queue.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Queue& queue) {
    std::shared_ptr<Queue::Node> cursor = queue.head;
    while(cursor) {
        os << cursor->val << " ";
        cursor = cursor->next;
    }
    return os;
}

Queue::Node::Node(int val) {
    this->val = val;
    child_count = 0;
}

void Queue::push(const int& val) {
    if (front) {
        std::shared_ptr<Queue::Node>& child = (front->child_count == 1 ? front->right : front->left);
        child.reset(new Node(val));
        child->prev = tail;
        child->parent = front;
        tail->next = child;
        tail = child;
        front->child_count++;
        if (front->child_count == 1) {
            front = front->next;
        }
        buble_up();
    }
    else {
        front.reset(new Node(val));
        head = front;
        tail = front;
    }
}

void Queue::buble_up() {
    std::shared_ptr<Queue::Node> cursor = tail;
    while (cursor->parent) {
        if (cursor->val > cursor->parent->val) {
            int temp = cursor->val;
            cursor->val = cursor->parent->val;
            cursor->parent->val = temp;
            cursor = cursor->parent;
        }
        else break;
    }
}

void Queue::pop() {
    head->val = tail->val;
    buble_down();
    if (front->child_count==2) {
        front->child_count--;
    }
    else {
        front->child_count--;
        front = front->prev;
    }
    if (tail->prev) {
        tail = tail->prev;
        tail->next->parent.reset();
        tail->next->prev.reset();
        tail->next.reset();
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
    while(cursor->left && cursor->right) {
        if (cursor->left->val > cursor->val) {
            int temp = cursor->val;
            cursor->val = cursor->left->val;
            cursor->left->val = temp;
            cursor = cursor->left;
        }
        else if (cursor->right->val > cursor->val) {
            int temp = cursor->val;
            cursor->val = cursor->right->val;
            cursor->right->val = temp;
            cursor = cursor->right;
        }
        else break;
    }
    if (cursor->left) {
        if (cursor->left->val > cursor->val) {
            int temp = cursor->val;
            cursor->val = cursor->left->val;
            cursor->left->val = temp;
        }
    }
}