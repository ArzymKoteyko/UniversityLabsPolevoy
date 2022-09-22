#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
#include "queue.hpp"


TEST_CASE("Checking QueueP constructor") {
    QueueP test_queue = QueueP();
    CHECK(test_queue.is_empty() == true);
}

void queue_push_array_and_check(std::vector<int>& push_array) {
    std::vector<int> queue_inspecor;
    QueueP inspecting_queue;
    bool identical = true;
    for (int i : push_array) {
        queue_inspecor.push_back(i);
        std::sort(queue_inspecor.begin(), queue_inspecor.end());
        inspecting_queue.push(i);
        if (inspecting_queue.top() != queue_inspecor[0]) {
            identical = false;
        }
    }
    CHECK(identical == true);
}

TEST_CASE("QueueP push method") {
    QueueP test_queue = QueueP();
    std::vector<int> sample;
    sample = {5,4,3,2,1};
    queue_push_array_and_check(sample);
    sample = {1,2,3,4,5};
    queue_push_array_and_check(sample);
}
