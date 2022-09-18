set(BINARY ${CMAKE_PROJECT_NAME})

# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

find_package(Threads REQUIRED)

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})

message(STATUS "From src spdlog source dir is ${spdlog_SOURCE_DIR}")

# include(../dependencies.cmake)

# target_include_directories(${BINARY}_run PRIVATE ${spdlog_SOURCE_DIR}/include)

target_link_libraries(${BINARY}_run PRIVATE Threads::Threads)