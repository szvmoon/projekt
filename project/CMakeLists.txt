cmake_minimum_required(VERSION 3.10)

#Configuration parameters of cmake
set(CMAKE_CXX_COMPILER g++)#requires g++ to be available on PATH
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Project)
enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

#Source files here
set(SOURCE_FILES
        src/Interface.cpp
        src/TextInterface.cpp
        include/TextInterface.h
        include/Interface.h
        src/main.cpp src/Game.cpp include/Game.h src/Player.cpp include/Player.h src/Unit.cpp include/Unit.h src/Basic.cpp include/Basic.h src/Timed.cpp include/Timed.h src/Board.cpp include/Board.h src/Field.cpp include/Field.h src/Checker.cpp include/Checker.h src/Bishop.cpp include/Bishop.h src/Rook.cpp include/Rook.h src/King.cpp include/King.h include/typedefs.h)

add_executable(Project ${SOURCE_FILES})

target_include_directories(Project PUBLIC include)

#TESTs
find_package(Boost 1.65 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

enable_testing()

#Test source files here
set(SOURCE_TEST_FILES
        src/Game.cpp src/main.cpp include/Game.h src/Player.cpp include/Player.h src/Unit.cpp include/Unit.h src/Basic.cpp include/Basic.h src/Timed.cpp include/Timed.h src/Board.cpp include/Board.h src/Field.cpp include/Field.h src/Checker.cpp include/Checker.h src/King.cpp include/King.h include/typedefs.h)

add_executable(TestProject ${SOURCE_TEST_FILES})

target_include_directories(TestProject PUBLIC include)

target_link_libraries(TestProject
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(NAME Test COMMAND TestProject
        --report_level=detailed
        --log_level=all
        --color_output=yes)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})