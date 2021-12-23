cmake_minimum_required(VERSION 3.0.0)

# if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
#   set(CMAKE_TOOLCHAIN_FILE "/home/hdc/Downloads/vcpkg/scripts/buildsystems/vcpkg.cmake"
#       CACHE STRING "")
# endif()

project(main VERSION 0.1.0)

# find_path(CATCH_INCLUDE_DIR NAMES tinyxml2.h PATH_SUFFIXES tinyxml2)
# include_directories(${CATCH_INCLUDE_DIR})

# find_package(tinyxml2 CONFIG REQUIRED)

include(CTest)
enable_testing()

add_executable(main ${CMAKE_CURRENT_LIST_DIR}/src/main04.cpp)
# target_link_libraries(main PRIVATE tinyxml2::tinyxml2)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(main PRIVATE Threads::Threads)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
