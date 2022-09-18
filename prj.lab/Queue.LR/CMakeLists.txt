add_library(queue queue.cpp)

add_executable(test test.cpp)

target_link_libraries(test queue)