cmake_minimum_required(VERSION 3.6)
project("TicTacToe" VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ========= Dependencies =========

set(RAYLIB_VERSION 5.0)

find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

set(SOURCE_FILES
    main.c
    table.c)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} raylib)

# Platform-specific compilation options

if(WIN32 AND MSVC)
    message("Target toolset: Win32 + MSVC.")

    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE /W3)

    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        message("Applying compile options for debugging in MSVC...")

        target_compile_options(${CMAKE_PROJECT_NAME}
        PRIVATE /fsanitize=address
        PRIVATE /Zi)

        target_link_options(${CMAKE_PROJECT_NAME}
        PRIVATE /INCREMENTAL:NO
        PRIVATE /DEBUG)
    endif()
elseif(LINUX)
    message("Target platform: Linux.")

    target_compile_options(${CMAKE_PROJECT_NAME}
    PRIVATE -Wall
    PRIVATE -Wextra
    PRIVATE -pedantic)

    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(DEBUG "Applying debugging symbols...")

        target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -g)
    else()
        message(VERBOSE "Applying compile optimization options...")

        target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -O3)
    endif()
endif()