### Below is OK make librpc.a manual.

cmake_minimum_required(VERSION 3.0.0)
project(Web_AquaGWAS)

# add_subdirectory(rpclib)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/rpclib/include)
include_directories(${PROJECT_SOURCE_DIR}/include/)

set (SRC 
    src/util.cpp 
    src/mainworker.cpp 
    src/plink.cpp
    src/gemma.cpp
    src/gwasrunner.cpp
)

add_executable(server server.cpp ${SRC})
add_executable(client client.cpp)
add_executable(main main.cpp ${SRC})

if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE "Debug")
endif()
# 设置编译参数
set(CXX_FLAGS
-g
-Wall
-std=c++1z
-pthread
-Wno-unused-parameter
)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O0")
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")  
string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)

# 链接rpc静态库
target_link_libraries(client ${PROJECT_SOURCE_DIR}/rpclib/librpc.a)
target_link_libraries(server ${PROJECT_SOURCE_DIR}/rpclib/librpc.a)