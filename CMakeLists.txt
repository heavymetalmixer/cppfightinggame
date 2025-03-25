cmake_minimum_required(VERSION 3.27)

# Select the C standard and compiler. This is crucial to compile Raylib
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_COMPILER gcc) # gcc, clang or cl
set(CMAKE_C_EXTENSIONS OFF)

# set(CMAKE_C_FLAGS_DEBUG "-v -fdiagnostics-color=always -m64 -O0 -g3 -Wpedantic -fsanitize=undefined -fsanitize-trap=all -lpthread -std=c${CMAKE_C_STANDARD}" CACHE STRING "" FORCE)
# set(CMAKE_C_FLAGS_RELEASE "-v -fdiagnostics-color=always -m64 -O3 -g0 -Wpedantic -std=c${CMAKE_C_STANDARD}" CACHE STRING "" FORCE)
# set(CMAKE_C_FLAGS_RELWITHDEBINFO "-v -fdiagnostics-color=always -m64 -O2 -g3 -Wpedantic -std=c${CMAKE_C_STANDARD}" CACHE STRING "" FORCE)
# The option -DNDEBUG disables all runtime asserts, AKA C-asserts

set(CMAKE_C_FLAGS_DEBUG "-fdiagnostics-color=always -m64 -O0 -g3 -Wpedantic -std=c${CMAKE_C_STANDARD}" CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS_RELWITHDEBINFO "-fdiagnostics-color=always -m64 -O2 -g3 -Wpedantic -std=c${CMAKE_C_STANDARD}" CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS_RELEASE "-fdiagnostics-color=always -m64 -DNDEBUG -O3 -g0 -Wpedantic -std=c${CMAKE_C_STANDARD}" CACHE STRING "" FORCE)

# Select the C++ standard and compiler
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER g++) # g++, clang++ or cl
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS_DEBUG "-v -fdiagnostics-color=always -m64 -O0 -g3 -Wpedantic -std=c++${CMAKE_CXX_STANDARD}" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-v -fdiagnostics-color=always -m64 -O2 -g3 -Wpedantic -std=c++${CMAKE_CXX_STANDARD}" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE "-v -fdiagnostics-color=always -m64 -DNDEBUG -O3 -g0 -Wpedantic -std=c++${CMAKE_CXX_STANDARD}" CACHE STRING "" FORCE)

project(CppFightingGame VERSION 0.0.1 LANGUAGES CXX)

# If the user doesn't provide a build type, choose Debug by default
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

if(CMAKE_BUILD_TYPE)
	message("\nUsing configuraton generation with the ${CMAKE_BUILD_TYPE} configuration type!\n")
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY VALUE "${CMAKE_BUILD_TYPE}")
else()
	message("Defaulting to Debug build.\n")
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY VALUE "Debug")
endif()

# Adds the CMakeLists.txt of the Raylib submodule to compile it and link it
# The first parameter is the path to the Raylib CMakeLists.txt folder
# The second parameter is a relative path to compile Raylib, from the build folder in the main project
# So for libs the compiled Raylib files will appear on build/libs/raylib
add_subdirectory(libs/raylib libs)

option(BUILD_SHARED_LIBS "Enable compilation of shared/dynamic libraries" OFF)
option(ENABLE_TESTING "Enable testing builds" OFF)

add_executable(${PROJECT_NAME} "src/CppFightingGame.cpp")
target_link_libraries(${PROJECT_NAME} PUBLIC raylib)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR})
