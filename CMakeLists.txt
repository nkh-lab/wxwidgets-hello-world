#
# Copyright (C) 2022 https://github.com/nkh-lab
#
# This is free software. You can redistribute it and/or
# modify it under the terms of the GNU General Public License
# version 3 as published by the Free Software Foundation.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY.
#

cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(wxwidgets-hello-world)

if(CMAKE_SYSTEM_NAME STREQUAL Linux)
    add_compile_options(-Wall -Werror -Wextra)

    option(${PROJECT_NAME}_BUILD_PORTABLE   "Build portable binaries"   OFF)

    if(${PROJECT_NAME}_BUILD_PORTABLE)
        set(CMAKE_INSTALL_RPATH "\$ORIGIN")
        set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)
    endif()

    ### wxWidgets ###
    # Defines
    add_definitions(-D__WXGTK__)
    # Suppress warnings 
    add_compile_options(-Wno-deprecated-copy)
    #################

elseif(CMAKE_SYSTEM_NAME STREQUAL Windows)
    add_definitions(-D__PRETTY_FUNCTION__=__FUNCSIG__)

    ### wxWidgets ###
    # Support find_package(wxWidgets REQUIRED) as prebuilt
    set(wxWidgets_ROOT_DIR ${CMAKE_SOURCE_DIR}/prebuilt/wxwidgets)
    set(wxWidgets_LIB_DIR ${CMAKE_SOURCE_DIR}/prebuilt/wxwidgets/lib/Debug)
    set(wxWidgets_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/prebuilt/wxwidgets/include)
    # Defines
    add_definitions(-DWXUSINGDLL)
    # Link options
    add_link_options(/SUBSYSTEM:WINDOWS)
    #################
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

