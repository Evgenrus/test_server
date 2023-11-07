cmake_minimum_required(VERSION 3.26)
project(test_opc_server)

set(CMAKE_CXX_STANDARD 23)

find_package(open62541pp CONFIG REQUIRED)
find_package(open62541 REQUIRED)

add_executable(test_opc_server main.cpp)
target_link_libraries(test_opc_server open62541)
target_link_libraries(test_opc_server open62541pp)