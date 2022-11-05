cmake_minimum_required(VERSION 3.15)
add_subdirectory(libDB)
project(DB)
set(CMAKE_CXX_FLAGS "-fuse-ld=lld")
file(GLOB DB_SRC "src/*.cc")
add_executable(DB ${DB_SRC})
target_link_libraries(DB PUBLIC libDB)
target_include_directories(DB PUBLIC "${PROJECT_BINARY_DIR}"
                                     "${PROJECT_SOURCE_DIR}/libDB/include"
                                     "${PROJECT_SOURCE_DIR}/include")
