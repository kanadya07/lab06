cmake_minimum_required(VERSION 3.10)

project(lab03 LANGUAGES CXX)

set(LAB06_VERSION_MAJOR 0)
set(LAB06_VERSION_MINOR 1)
set(LAB06_VERSION_PATCH 0)
set(LAB06_VERSION_TWEAK 0)
set(LAB06_VERSION
  ${LAB06_VERSION_MAJOR}.${LAB06_VERSION_MINOR}.${LAB06_VERSION_PATCH}.${LAB06_VERSION_TWEAK}
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build unit tests" ON)

add_subdirectory(formatter_lib)
add_subdirectory(formatter_ex_lib)
add_subdirectory(solver_lib)
add_subdirectory(hello_world_application)
add_subdirectory(solver_application)
add_subdirectory(banking)

if(BUILD_TESTS)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  )
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)

  enable_testing()
  add_executable(check
    tests/account_test.cpp
    tests/transaction_test.cpp
  )
  target_link_libraries(check PRIVATE banking gtest_main gmock)
  add_test(NAME check COMMAND check)
endif()

include(CPackConfig.cmake)
