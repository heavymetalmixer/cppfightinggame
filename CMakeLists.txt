cmake_minimum_required(VERSION 3.27)

# We are building a C Game
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_COMPILER gcc) # gcc, clang or cl

# set(CMAKE_C_FLAGS_DEBUG "-v -fdiagnostics-color=always -m64 -O0 -g3 -Wpedantic -fsanitize=undefined -fsanitize-trap=all -lpthread -std=c${CMAKE_C_STANDARD}" CACHE STRING "" FORCE)
# set(CMAKE_C_FLAGS_RELEASE "-v -fdiagnostics-color=always -m64 -O3 -g0 -Wpedantic -std=c${CMAKE_C_STANDARD}" CACHE STRING "" FORCE)
# set(CMAKE_C_FLAGS_RELWITHDEBINFO "-v -fdiagnostics-color=always -m64 -O2 -g3 -Wpedantic -std=c${CMAKE_C_STANDARD}" CACHE STRING "" FORCE)

set(CMAKE_C_FLAGS_DEBUG "-fdiagnostics-color=always -m64 -O0 -g3 -Wpedantic -std=c${CMAKE_C_STANDARD}" CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS_RELEASE "-fdiagnostics-color=always -m64 -O3 -g0 -Wpedantic -std=c${CMAKE_C_STANDARD}" CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS_RELWITHDEBINFO "-fdiagnostics-color=always -m64 -O2 -g3 -Wpedantic -std=c${CMAKE_C_STANDARD}" CACHE STRING "" FORCE)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER g++) # g++, clang++ or cl

set(CMAKE_CXX_FLAGS_DEBUG "-v -fdiagnostics-color=always -m64 -O0 -g3 -Wpedantic -std=c${CMAKE_C_STANDARD}" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE "-v -fdiagnostics-color=always -m64 -O3 -g0 -Wpedantic -std=c${CMAKE_C_STANDARD}" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-v -fdiagnostics-color=always -m64 -O2 -g3 -Wpedantic -std=c${CMAKE_C_STANDARD}" CACHE STRING "" FORCE)

project(CppFightingGame VERSION 0.0.1 LANGUAGES CXX)

include(${PROJECT_SOURCE_DIR}/libs/raylib/raylib_5.5/raylib/cmake/raylib-config)
# include(${PROJECT_SOURCE_DIR}/libs/raylib/raylib_5.5/raylib/CMakeOptions.txt)
# include(${PROJECT_SOURCE_DIR}/libs/raylib/raylib_5.5/raylib/cmake/CompilerFlags)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()



# # Download Raylib
# include(FetchContent)
# FetchContent_Declare(
#     raylib GIT_REPOSITORY "https://github.com/raysan5/raylib.git",
#     GIT_TAG c1ab645ca298a2801097931d1079b10ff7eb9df8 # release-5.5-stable
# )
# FetchContent_MakeAvailable(raylib)

# include_directories(., src/, src/utils/, src/ActionStates/, libs/raylib/raylib_5.5/raylib/)
# add_subdirectory(src/)
# add_subdirectory(src/utils/)
# add_subdirectory(src/ActionStates/)
# add_subdirectory(libs/raylib/raylib_5.5/raylib/)

add_library(raylib INTERFACE)
target_link_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/libs/raylib/raylib_5.5/raylib/src/)
target_link_libraries(${PROJECT_NAME} INTERFACE raylib)

# add_library(raylib raylib.h)
# target_link_libraries(${PROJECT_NAME} "libs/raylib/raylib_5.5/raylib/src/raylib.h")

# Include and Link Raylib in the game
add_executable(${PROJECT_NAME} "src/CppFightingGame.cpp")
# target_link_libraries(${PROJECT_NAME} "libs/raylib/raylib_5.5/raylib/raylib.h")
# target_link_libraries(${PROJECT_NAME} raylib)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR})

# cmake -S . -G "Visual Studio 17 2022" -B build -DCMAKE_C_COMPILER=cl
