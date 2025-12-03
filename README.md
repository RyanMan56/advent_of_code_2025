# Advent of Code 2025

My solutions for the Advent of Code 2025, written in C++

## How to run

1. Create a `build` directory, e.g. `mkdir build`
2. Generate a native build system, `cd build && cmake ..`
3. Compile/link the project, `cmake --build .`
4. Navigate into the bin directory, `cd bin`
5. Run the project `./AdventOfCode2025` (assuming you're on mac/linux. You'll probably just want to open and run the project in VS if you're on windows)

There are a couple of handy scripts for mac/linux (I haven't created these for windows yet). Make sure to cd into the scripts directory and run them from there:

- `scripts/build.sh` - cds into the build directory, generates a native build system, compiles/links the project, and runs the executable
- `scripts/clean_build.sh` - removes the `build` directory and runs `build.sh`
- `scripts/quick_build.sh` - compiles/links the project and runs the executable. Doesn't generate the native build system (not needed because of CONFIGURE_DEPENDS)

### Notes

- To get debugging working you may have to follow these steps:

  1. Open the Command Palette and search for `CMake: Configure`. This will configure your project for building.
  2. Once configured, build the project by selecting `CMake: Build` or running the build task.
