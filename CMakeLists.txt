cmake_minimum_required(VERSION 3.13)
project(root_event_tree_cmake)

set(CMAKE_CXX_STANDARD 17)

# Find ROOT
find_package(ROOT REQUIRED COMPONENTS RIO)
message("-- Found ROOT version ${ROOT_VERSION}")

add_executable(root_event_tree_cmake main.cpp)

target_link_libraries(${PROJECT_NAME} ${ROOT_LIBRARIES} ROOT::RIO)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/include/DataModel.h DESTINATION .)
