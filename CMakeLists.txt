cmake_minimum_required(VERSION 3.10)
project(eb_authen_server)
aux_source_directory(./ SRC_FILES_LIST)

include_directories(include)

set(LINK_DDIR ${PROJECT_SOURCE_DIR}/lib)
set(LINK_SDIR ${PROJECT_SOURCE_DIR}/lib)
link_directories(${LINK_DDIR})
link_directories(${LINK_SDIR})

add_executable(${PROJECT_NAME} ${SRC_FILES_LIST})
add_executable(echo_http_server echo_http_server.cpp)
target_link_libraries(echo_http_server evpp_static  event_pthreads event glog gflags ssl crypto pthread)