cmake_minimum_required(VERSION 3.0.0)
project(linear_regression VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(linear_regression linear_regression.c example.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
