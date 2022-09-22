add_library(queuep queue.cpp)

add_executable(test test.cpp)

target_link_libraries(test queuep)