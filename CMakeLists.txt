cmake_minimum_required(VERSION 3.10)
project(eb_authen_server)


include_directories(include)
include_directories(ebresult)

aux_source_directory(./ SRC_FILES_LIST)
aux_source_directory(ebresult SRC_FILE_LIST)

set(LINK_DDIR ${PROJECT_SOURCE_DIR}/lib)
set(LINK_SDIR ${PROJECT_SOURCE_DIR}/lib)
link_directories(${LINK_DDIR})
link_directories(${LINK_SDIR})


add_executable(${PROJECT_NAME} ${SRC_FILES_LIST})
add_executable(echo_http_server example/echo_http_server.cpp)
add_executable(libco_example example/libco_example.cpp)

target_link_libraries(${PROJECT_NAME} evpp_static  event_pthreads event glog gflags ssl crypto pthread)

target_link_libraries(echo_http_server evpp_static  event_pthreads event glog gflags ssl crypto pthread)

target_link_libraries(libco_example libco)