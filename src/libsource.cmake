message(STATUS "from src/libsource.cmake CMAKE_CURRENT_LIST_DIR is ${CMAKE_CURRENT_LIST_DIR}")
set(libsoure ${CMAKE_CURRENT_LIST_DIR}/components.cpp
            ${CMAKE_CURRENT_LIST_DIR}/Formula.cpp
            ${CMAKE_CURRENT_LIST_DIR}/header.cpp)


set(mainappsoure ${CMAKE_CURRENT_LIST_DIR}/components.cpp
            ${CMAKE_CURRENT_LIST_DIR}/Formula.cpp
            ${CMAKE_CURRENT_LIST_DIR}/header.cpp
            ${CMAKE_CURRENT_LIST_DIR}/main.cpp)