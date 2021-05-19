cmake_minimum_required(VERSION 3.10)

# set the project name
project(BIDS)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/)

file (GLOB files */*.cpp)
foreach(file ${files})
    string(REGEX REPLACE ".+/(.+)/(.+)\\..*" "\\1.\\2" exe ${file})
    add_executable(${exe} ${file})
    message(\ \ \ \ ${exe}.cpp\ will\ be\ compiled\ to\ bin /${exe})
endforeach()
