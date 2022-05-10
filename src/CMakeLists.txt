add_library(LinearRegression STATIC linear_regression.c)

target_include_directories(LinearRegression PUBLIC ${CMAKE_CURRENT_LIST_DIR})