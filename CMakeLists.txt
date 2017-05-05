project(backstack)
cmake_minimum_required(VERSION 3.0)

# sudo apt-get install binutils-dev
# sudo apt-get install libdw-dev

add_subdirectory("${CMAKE_BINARY_DIR}/backward-cpp")
include_directories("${CMAKE_BINARY_DIR}/backward-cpp")

#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/backward-cpp/BackwardConfig.cmake")
#message(${CMAKE_MODULE_PATH})
#find_package(Backward)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -O3 -g3 -std=c++14 -Wall -pedantic")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -std=c++14 -Wall -pedantic")

# This will add backward.cpp to your target
add_executable(${PROJECT_NAME} "backstack.cpp")

# This will add libraries, definitions and include directories needed by backward
# by setting each property on the target.

#target_link_libraries(${PROJECT_NAME} -ldl -lbfd)
#target_link_libraries(${PROJECT_NAME})
add_backward(${PROJECT_NAME})
