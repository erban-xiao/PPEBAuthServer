cmake_minimum_required(VERSION 3.10)
project(eb_authen_server)


include_directories(include)


set(LINK_DDIR ${PROJECT_SOURCE_DIR}/lib)
set(LINK_SDIR ${PROJECT_SOURCE_DIR}/lib)
link_directories(${LINK_DDIR})
link_directories(${LINK_SDIR})

INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(ebresult)
INCLUDE_DIRECTORIES(ebexception)
INCLUDE_DIRECTORIES(ebhttp)

aux_source_directory(./ SRC_FILES_LIST)
aux_source_directory(ebresult SRC_FILES_LIST)
aux_source_directory(ebjsonparser SRC_FILES_LIST)
aux_source_directory(ebexception SRC_FILES_LIST)
aux_source_directory(ebbusinessprocess SRC_FILES_LIST)
aux_source_directory(ebhttp SRC_FILES_LIST)
aux_source_directory(ebhttp/protocol SRC_FILES_LIST)

add_executable(${PROJECT_NAME} ${SRC_FILES_LIST})


#add_executable(echo_http_server example/echo_http_server.cpp)
#add_executable(libco_example example/libco_example.cpp)

target_link_libraries(${PROJECT_NAME} colib evpp_static event_pthreads event glog gflags fmt ssl crypto pthread dl)

#target_link_libraries(echo_http_server evpp_static  event_pthreads event glog gflags fmt ssl crypto pthread)

#target_link_libraries(libco_example libco fmt)