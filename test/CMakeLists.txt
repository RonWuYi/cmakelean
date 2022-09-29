set(BINARY ${CMAKE_PROJECT_NAME}_test)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # using Visual Studio C++
  message("Using Visual Studio C++")
  set(gtest_force_shared_crt on)
endif()

# include(../dependencies.cmake)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

message(STATUS "from root cmake CMAKE_CURRENT_LIST_DIR is ${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(${BINARY} PRIVATE ${spdlog_SOURCE_DIR}/include )

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest gmock)