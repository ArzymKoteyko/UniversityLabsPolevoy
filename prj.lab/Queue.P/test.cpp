#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
#include <ctime>
#include "queue.hpp"




// Testing default constructor

TEST_CASE("Checking QueueP default constructor") {
    QueueP test_queue = QueueP();
    CHECK(test_queue.is_empty() == true);
}




// Testing push method

bool queue_push_sample_and_check(const std::vector<int>& sample) {
    std::vector<int> queue_inspecor;
    QueueP inspecting_queue;
    bool identical = true;
    for (int i : sample) {
        queue_inspecor.push_back(i);
        std::sort(queue_inspecor.begin(), queue_inspecor.end());
        inspecting_queue.push(i);
        if (inspecting_queue.top() != queue_inspecor[0]) {
            identical = false;
        }
    }
    return identical;
}

bool queue_push_random_samples_and_check(const int number_of_tests, const int sample_size = 10) {
    bool pass = true;
    for (int i=0; i<number_of_tests; ++i) {
        std::time_t seed = std::time(nullptr);
        std::srand(seed);
        std::vector<int> sample;
        for (int i=0; i<sample_size; ++i) {
            sample.push_back(std::rand());
        }
        pass = queue_push_sample_and_check(sample);
        if (pass == false) {
            std::cout << seed << std::endl;
            for (int i : sample) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
    }
    return pass;
}

TEST_CASE("QueueP push method") {
    QueueP queue;
    CHECK(queue.is_empty() == true);
    queue.push(0);
    CHECK(queue.is_empty() == false);
    CHECK(queue.top() == 0);

    std::vector<int> sample;
    sample = {1,1,1,1,1};
    CHECK(queue_push_sample_and_check(sample));
    sample = {1,2,3,4,5};
    CHECK(queue_push_sample_and_check(sample));
    sample = {5,4,3,2,1};
    CHECK(queue_push_sample_and_check(sample));
    sample = {1,5,4,3,2};
    CHECK(queue_push_sample_and_check(sample));
    CHECK(queue_push_random_samples_and_check(100));
}




// Testing pop method

void queue_push_smaple(QueueP& queue, const std::vector<int> sample) {
    for (int i : sample) {
        queue.push(i);
    }
}

void queue_from_sample_pop_all_and_check(std::vector<int>& sample) {
    QueueP queue;
    queue_push_smaple(queue, sample);
    std::sort(sample.begin(), sample.end());
    for (int i : sample) {
        CHECK(queue.is_empty() == false);
        CHECK(queue.top() == i);
        queue.pop();
    }
    CHECK(queue.is_empty() == true);
}

TEST_CASE("QueueP pop method") {
    QueueP queue;
    queue.push(0);
    queue.pop();
    CHECK(queue.is_empty() == true);
    std::vector<int> sample;
    sample = {1,2,3,4,5};
    queue_from_sample_pop_all_and_check(sample);
    sample = {5,4,3,2,1};
    queue_from_sample_pop_all_and_check(sample);
    sample = {1,5,4,3,2};
    queue_from_sample_pop_all_and_check(sample);
    sample = {1,1,1,1,1};
    queue_from_sample_pop_all_and_check(sample);
    sample = {1,1,1,2,2};
    queue_from_sample_pop_all_and_check(sample);
}




// Testing copy constructor

TEST_CASE("Checking QueueP copy constructor") {
    SUBCASE("copy an empty queue") {
        QueueP a_queue;
        QueueP b_queue(a_queue);
        SUBCASE("check if queues stay empty") {
            CHECK(a_queue.is_empty());
            CHECK(b_queue.is_empty());
        }
        SUBCASE("check if queues are independed") {
            a_queue.push(1);
            b_queue.push(-1);
            CHECK(a_queue.top() == 1);
            CHECK(b_queue.top() == -1);
            a_queue.push(0);
            b_queue.push(-2);
            CHECK(a_queue.top() == 0);
            CHECK(b_queue.top() == -2);
            a_queue.push(5);
            b_queue.push(5);
            CHECK(a_queue.top() == 0);
            CHECK(b_queue.top() == -2);
        }
    }
    SUBCASE("copy a non-empty queue") {
        std::vector<int> sample = {1,2,3,4,5};
        QueueP a_queue;
        queue_push_smaple(a_queue, sample);
        QueueP b_queue(a_queue);
        CHECK(!a_queue.is_empty());
        CHECK(!b_queue.is_empty());
        while (!a_queue.is_empty()) {
            CHECK(a_queue.top() == b_queue.top());
            a_queue.pop();
            b_queue.pop();
        }
    }
}




// Testing move constructor

TEST_CASE("Checkking QueueP move constructor") {
    std::vector<int> sample = {1,2,3,4,5};
    QueueP a_queue;
    queue_push_smaple(a_queue, sample);
    QueueP b_queue = std::move(a_queue);
    CHECK(a_queue.is_empty());
    CHECK(!b_queue.is_empty());
    for (int i : sample) {
        CHECK(b_queue.top() == i);
        b_queue.pop();
    }
}