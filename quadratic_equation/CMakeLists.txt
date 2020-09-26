cmake_minimum_required(VERSION 3.4)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.251.tar.gz"
    SHA1 "5659b15dc0884d4b03dbd95710e6a1fa0fc3258d"
)

project(quadratic_equation)

option(BUILD_TESTS "Build tests" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(MYCOMPILE_FLAGS "-Wall -Wextra -pedantic -O3 -Wshadow -Wformat=2 \
-Wfloat-equal -Wconversion -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG \
-D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address,undefined \
-fno-sanitize-recover=all -fstack-protector")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MYCOMPILE_FLAGS} -std=c++17 ")

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_library(solve_equation STATIC ${CMAKE_CURRENT_SOURCE_DIR}/source/solve_equation.cpp)
target_include_directories(solve_equation PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

set(SOURCE_EXE ${CMAKE_CURRENT_SOURCE_DIR}/source/quadratic_equation.cpp)		# Установка переменной со списком исходников для исполняемого файла
add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main
target_link_libraries(main solve_equation m)		# Линковка программы с библиотекой

if(BUILD_TESTS)
    enable_testing()
    file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
    add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
    target_link_libraries(check solve_equation GTest::gtest_main)
    add_test(NAME check COMMAND check)
endif()