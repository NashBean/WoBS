cmake_minimum_required(VERSION 3.21)
project(WoBS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   # for clangd / VSCode

# ---------- Core library ----------
add_library(wobs_core STATIC
    src/core/Grid.cpp
    src/core/Position.cpp
    src/core/Bot.cpp
    src/core/Physics.cpp
    src/core/AI.cpp
)
target_include_directories(wobs_core PUBLIC src/include)

# ---------- Desktop test executable ----------
add_executable(wobs_test
    src/main_test.cpp
)
target_link_libraries(wobs_test PRIVATE wobs_core)

# ---------- Android NDK build (later) ----------
# Will be added in section 6