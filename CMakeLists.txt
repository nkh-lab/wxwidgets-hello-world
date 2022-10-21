cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(wxwidgets-hello-world)

if(CMAKE_SYSTEM_NAME STREQUAL Linux)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")
elseif(CMAKE_SYSTEM_NAME STREQUAL Windows)
    # Support find_package(wxWidgets REQUIRED) as prebuilt
    set(wxWidgets_ROOT_DIR ${CMAKE_SOURCE_DIR}/prebuilt/wxwidgets)
    set(wxWidgets_LIB_DIR ${CMAKE_SOURCE_DIR}/prebuilt/wxwidgets/lib/Debug)
    set(wxWidgets_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/prebuilt/wxwidgets/include)

    # Compile flags
    ADD_DEFINITIONS(-DWXUSINGDLL)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")

    ADD_DEFINITIONS(-D__PRETTY_FUNCTION__=__FUNCSIG__)
endif()

find_package(wxWidgets REQUIRED)

file(GLOB SRC_FILES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME}
    PRIVATE src
    PRIVATE ${wxWidgets_INCLUDE_DIRS}
    )

target_link_libraries(${PROJECT_NAME}
    PRIVATE ${wxWidgets_LIBRARIES}
    )

