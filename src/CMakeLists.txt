set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCE_FILES
    main.c
    table.c
    button.c)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE raylib)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ../include/)

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