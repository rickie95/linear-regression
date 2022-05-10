cmake_minimum_required(VERSION 3.0)
project(linear_regression LANGUAGES C VERSION 0.1.0)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# Adds library subdir
add_subdirectory(src)

if(CMAKE_BUILD_TYPE STREQUAL Release)
    message( STATUS "CMAKE_BUILD_TYPE set to 'Release'")
elseif(CMAKE_BUILD_TYPE STREQUAL Test)
    include(CTest)
    add_subdirectory(unity)
    add_subdirectory(test)
elseif(CMAKE_BUILD_TYPE STREQUAL Debug)
    message( STATUS "CMAKE_BUILD_TYPE set to 'Debug'")
else()
    message( ERROR "TARGET_GROUP unknown. Possible values are debug, release, test.")
endif()

add_executable(linear_regression example.c)

# Link against library defined in src
target_link_libraries(linear_regression LINK_PUBLIC LinearRegression)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
