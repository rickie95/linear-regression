cmake_minimum_required(VERSION 3.0)
project(linear_regression LANGUAGES C VERSION 0.1.0)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(TARGET_GROUP test CACHE STRING "Version to build")

# Adds library subdir
add_subdirectory(src)

enable_testing()
include(CTest)
add_subdirectory(unity)
add_subdirectory(test)

if(TARGET_GROUP STREQUAL release)
    message( STATUS "CMAKE_BUILD_TYPE set to 'Release'")
elseif(TARGET_GROUP STREQUAL test)
    message( STATUS "CMAKE_BUILD_TYPE set to 'Test'")
   
elseif(TARGET_GROUP STREQUAL debug)
    message( STATUS "CMAKE_BUILD_TYPE set to 'Debug'")
else()
    message( STATUS "TARGET_GROUP unknown. Possible values are debug, release, test.")
endif()

# example.c is an executable, compile it and link against the lib
add_executable(linear_regression example.c)
# Link against library defined in src
target_link_libraries(linear_regression LINK_PUBLIC LinearRegression)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
