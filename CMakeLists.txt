cmake_minimum_required(VERSION 3.0.0)
project(Elevator VERSION 0.1.0)

file(GLOB sources ./src/*.cpp ./inc/*.h)
set(${PROJECT_NAME} ${sources})

set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} ${sources})
target_include_directories(${PROJECT_NAME} PRIVATE ./inc)
target_link_libraries(${PROJECT_NAME} Threads::Threads)


add_subdirectory(unit_test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
