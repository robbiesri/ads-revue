# Copyright (c) 2025 Robert Srinivasiah
# Help from Claude + Gemini

cmake_minimum_required(VERSION 3.31)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(doctest)

function(add_program PROGRAM_NAME SOURCE_FILE)
    # Create executable
    add_executable(${PROGRAM_NAME} ${SOURCE_FILE})
endfunction()

# Function to easily add a program with tests
function(add_program_embedded_test PROGRAM_NAME SOURCE_FILE)
    # Create executable
    add_executable(${PROGRAM_NAME} ${SOURCE_FILE})

    # Link doctest
    target_link_libraries(${PROGRAM_NAME} PRIVATE doctest::doctest)

    # Add as test
    add_test(NAME ${PROGRAM_NAME}_test COMMAND ${PROGRAM_NAME})
endfunction()

# Example usage - uncomment and modify as needed:
# add_program_embedded_test(example src/example.cpp)
# add_program_embedded_test(math_utils src/math_utils.cpp)

# Alternative: if you want separate test files
function(add_program_separate_tests PROGRAM_NAME MAIN_FILE TEST_FILE)
    # Create main executable
    add_executable(${PROGRAM_NAME} ${MAIN_FILE})

    # Create test executable
    add_executable(${PROGRAM_NAME}_tests ${TEST_FILE} ${MAIN_FILE})
    target_link_libraries(${PROGRAM_NAME}_tests PRIVATE doctest::doctest)

    # Add test
    add_test(NAME ${PROGRAM_NAME}_tests COMMAND ${PROGRAM_NAME}_tests)
endfunction()

# Example for separate test files:
# add_program_separate_tests(calculator src/calculator.cpp tests/calculator_test.cpp)

# Optional: Add compile flags for better debugging
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(doctest::doctest INTERFACE -Wall -Wextra -g)
endif()

message(STATUS "")
message(STATUS "Usage:")
message(STATUS "  1. Create your source files in src/")
message(STATUS "  2. Use add_program(name src/file.cpp) for programs with embedded tests")
message(STATUS "  3. Use add_program_with_tests(name src/main.cpp tests/test.cpp) for separate test files")
message(STATUS "  4. Run 'cmake --build . && ctest' to build and test")
message(STATUS "")