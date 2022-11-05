cmake_minimum_required(VERSION 3.15)
project(libDB)
file(GLOB libDB_SRC "src/*.cc")
add_library(libDB ${libDB_SRC})