cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 99)

project(performance_test C)

include_directories(include)

set(SHARED_MEMORY_SRC
    src/memory_resources.c
)

set(MESSAGE_QUEUE_SRC
    src/queue_functions.c
)

set(EXECUTABLE_SRC
    src/main.c
    ${SHARED_MEMORY_SRC}
    ${MESSAGE_QUEUE_SRC}
)

add_executable(performance_test ${EXECUTABLE_SRC})
