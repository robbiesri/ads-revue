cmake_minimum_required(VERSION 3.31)
project(ads_revue)

#set(CMAKE_CXX_STANDARD 20)

add_subdirectory(cpp)

#include_directories(cpp/doctest/doctest)
#include_directories(cpp/doctest/doctest/extensions)
#include_directories(cpp/doctest/doctest/parts)
#include_directories(cpp/doctest/examples/all_features)
#include_directories(cpp/doctest/examples/combining_the_same_tests_built_differently_in_multiple_shared_objects)
#include_directories(cpp/doctest/examples/installed_doctest_cmake/dll)
#include_directories(cpp/doctest/scripts/development_only)
#include_directories(cpp/doctest/scripts/development_only/doctest)
#
#add_executable(ads_revue
#        cpp/doctest/doctest/extensions/doctest_mpi.h
#        cpp/doctest/doctest/extensions/doctest_util.h
#        cpp/doctest/doctest/extensions/mpi_reporter.h
#        cpp/doctest/doctest/extensions/mpi_sub_comm.h
#        cpp/doctest/doctest/parts/doctest.cpp
#        cpp/doctest/doctest/parts/doctest_fwd.h
#        cpp/doctest/doctest/doctest.h
#        cpp/doctest/examples/all_features/alternative_macros.cpp
#        cpp/doctest/examples/all_features/assert_returns_disabled.cpp
#        cpp/doctest/examples/all_features/assert_returns_disabled_evaluate.cpp
#        cpp/doctest/examples/all_features/assertion_macros.cpp
#        cpp/doctest/examples/all_features/asserts_used_outside_of_tests.cpp
#        cpp/doctest/examples/all_features/bitfield_packed_struct.cpp
#        cpp/doctest/examples/all_features/bitfields.cpp
#        cpp/doctest/examples/all_features/check_doctest_string.cpp
#        cpp/doctest/examples/all_features/concurrency.cpp
#        cpp/doctest/examples/all_features/coverage_maxout.cpp
#        cpp/doctest/examples/all_features/decomposition.cpp
#        cpp/doctest/examples/all_features/doctest_proxy.h
#        cpp/doctest/examples/all_features/double_stringification.cpp
#        cpp/doctest/examples/all_features/enums.cpp
#        cpp/doctest/examples/all_features/header.h
#        cpp/doctest/examples/all_features/logging.cpp
#        cpp/doctest/examples/all_features/main.cpp
#        cpp/doctest/examples/all_features/namespace1.cpp
#        cpp/doctest/examples/all_features/namespace2.cpp
#        cpp/doctest/examples/all_features/namespace3.cpp
#        cpp/doctest/examples/all_features/namespace4.cpp
#        cpp/doctest/examples/all_features/namespace5.cpp
#        cpp/doctest/examples/all_features/namespace6.cpp
#        cpp/doctest/examples/all_features/namespace7.cpp
#        cpp/doctest/examples/all_features/namespace8.cpp
#        cpp/doctest/examples/all_features/namespace9.cpp
#        cpp/doctest/examples/all_features/no_failures.cpp
#        cpp/doctest/examples/all_features/reporters_and_listeners.cpp
#        cpp/doctest/examples/all_features/stringification.cpp
#        cpp/doctest/examples/all_features/subcases.cpp
#        cpp/doctest/examples/all_features/templated_test_cases.cpp
#        cpp/doctest/examples/all_features/test_cases_and_suites.cpp
#        cpp/doctest/examples/combining_the_same_tests_built_differently_in_multiple_shared_objects/default.cpp
#        cpp/doctest/examples/combining_the_same_tests_built_differently_in_multiple_shared_objects/foo.h
#        cpp/doctest/examples/combining_the_same_tests_built_differently_in_multiple_shared_objects/main.cpp
#        cpp/doctest/examples/combining_the_same_tests_built_differently_in_multiple_shared_objects/return42.cpp
#        cpp/doctest/examples/combining_the_same_tests_built_differently_in_multiple_shared_objects/test_runner.cpp
#        cpp/doctest/examples/exe_with_static_libs/lib_1_src1.cpp
#        cpp/doctest/examples/exe_with_static_libs/lib_1_src2.cpp
#        cpp/doctest/examples/exe_with_static_libs/lib_2_src.cpp
#        cpp/doctest/examples/exe_with_static_libs/main.cpp
#        cpp/doctest/examples/executable_dll_and_plugin/dll.cpp
#        cpp/doctest/examples/executable_dll_and_plugin/implementation.cpp
#        cpp/doctest/examples/executable_dll_and_plugin/implementation_2.cpp
#        cpp/doctest/examples/executable_dll_and_plugin/main.cpp
#        cpp/doctest/examples/executable_dll_and_plugin/plugin.cpp
#        cpp/doctest/examples/installed_doctest_cmake/dll/dll.cpp
#        cpp/doctest/examples/installed_doctest_cmake/dll/dll.h
#        cpp/doctest/examples/installed_doctest_cmake/dll/exporting.h
#        cpp/doctest/examples/installed_doctest_cmake/dll/main.cpp
#        cpp/doctest/examples/installed_doctest_cmake/executable/main.cpp
#        cpp/doctest/examples/mpi/main.cpp
#        cpp/doctest/examples/mpi/mpi.cpp
#        cpp/doctest/scripts/development_only/doctest/doctest.h
#        cpp/doctest/scripts/how_stuff_works/how_exception_translators_work.cpp
#        cpp/doctest/scripts/how_stuff_works/how_subcases_work.cpp
#        cpp/doctest/scripts/how_stuff_works/testing_crash_scenarios.cpp
#        cpp/doctest/scripts/playground/main.cpp
#        cpp/doctest/scripts/playground/test.cpp
#        cpp/doctest/scripts/hello_world.cpp)
