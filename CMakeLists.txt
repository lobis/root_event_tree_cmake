cmake_minimum_required(VERSION 3.13)
project(root_event_tree_cmake)

set(CMAKE_CXX_STANDARD 17)

# Find ROOT
find_package(ROOT REQUIRED COMPONENTS RIO)
message("-- Found ROOT version ${ROOT_VERSION}")

add_executable(root_event_tree_cmake main.cpp src/DataModel.cpp)

target_link_libraries(${PROJECT_NAME} ROOT::RIO)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

ROOT_GENERATE_DICTIONARY(
        DataModel ${CMAKE_CURRENT_SOURCE_DIR}/include/DataModel.h
        MODULE DataModel
        LINKDEF ${CMAKE_CURRENT_SOURCE_DIR}/include/DataModelLinkDef.h
)
