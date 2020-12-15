cmake_minimum_required(VERSION 3.10)
project(eb_authen_server)
include_directories(third-party/ebcppframework/ebresult)
include_directories(third-party/ebcppframework/ebcoroutine)

add_subdirectory(third-party/ebcppframework)

add_executable(${PROJECT_NAME} main.cpp authenservice.cpp authenservice.h)
target_link_libraries(${PROJECT_NAME} eb_result eb_jsonparser eb_network libgo pthread dl)