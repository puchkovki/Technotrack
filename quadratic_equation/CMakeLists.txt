cmake_minimum_required(VERSION 3.4)

project(quadratic_equation)

#include_directories(include)

option(BUILD_TESTS "Build tests" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(MYCOMPILE_FLAGS "-Wall -Wextra -pedantic -O3 -Wshadow -Wformat=2 \
-Wfloat-equal -Wconversion -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG \
-D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address,undefined \
-fno-sanitize-recover=all -fstack-protector")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MYCOMPILE_FLAGS} -std=c++17 ")

add_library(solve_equation STATIC ${CMAKE_CURRENT_SOURCE_DIR}/source/solve_equation.cpp)
target_include_directories(solve_equation PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

set(SOURCE_EXE ${CMAKE_CURRENT_SOURCE_DIR}/source/quadratic_equation.cpp)		# Установка переменной со списком исходников для исполняемого файла
add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main
target_link_libraries(main solve_equation m)		# Линковка программы с библиотекой
install(TARGETS main RUNTIME DESTINATION bin)

install(TARGETS solve_equation
    EXPORT solve_equation-config
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
install(EXPORT solve_equation-config DESTINATION cmake)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(third-party/gtest)
    file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
    add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
    target_link_libraries(check solve_equation gtest_main)
    add_test(NAME check COMMAND check)
endif()