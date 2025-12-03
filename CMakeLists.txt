cmake_minimum_required(VERSION 3.15)

project(AdventOfCode2025 VERSION 1.0)

# Export compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Provide a single source of truth for compiler flags
add_library(advent_of_code_2025_compiler_flags INTERFACE)
target_compile_features(advent_of_code_2025_compiler_flags INTERFACE cxx_std_20)

# Compiler conditionals
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

# Add compile warning flags based on the compiler used from the flags above
target_compile_options(advent_of_code_2025_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-fcolor-diagnostics;-fansi-escape-codes;-Wall;-Wextra;-Wconversion;-Wsign-conversion;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_like_cxx}:$<BUILD_INTERFACE:-W3>>"
)

# Control where the static and shared libraries are built so that on Windows
# we don't need to mess with the PATH to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

# Gathers all cpp files in the src directory recursively
# CONFIGURE_DEPENDS ensures CMake checks for new/removed files on each build
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(AdventOfCode2025 src/main.cpp ${SOURCE_FILES})

# Copy assets to the binary directory so they can be found at runtime
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# Link the compiler flags and libraries to the executable
target_link_libraries(AdventOfCode2025 PUBLIC advent_of_code_2025_compiler_flags)

target_include_directories(AdventOfCode2025 PUBLIC "${PROJECT_BINARY_DIR}/src")

# Install the executable to the bin directory
install(TARGETS AdventOfCode2025 DESTINATION bin)
