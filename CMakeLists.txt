cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")

project(wxwidgets-hello-world)

find_package(wxWidgets REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__WXGTK__")

file(GLOB SRC_FILES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME}
    PRIVATE src
    PRIVATE ${wxWidgets_INCLUDE_DIRS}
    )

target_link_libraries(${PROJECT_NAME}
    PRIVATE ${wxWidgets_LIBRARIES}
    )

