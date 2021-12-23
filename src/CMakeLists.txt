cmake_minimum_required(VERSION 3.10)
project(ExampleProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)

# set(THREADS_PREFER_PTHREAD_FLAG ON)
# find_package(Threads REQUIRED)
# target_link_libraries(main PRIVATE Threads::Threads)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
