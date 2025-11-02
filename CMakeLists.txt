cmake_minimum_required(VERSION 3.10)
project(WoBS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(wobs_core STATIC
    src/core/Grid.cpp
    src/core/Position.cpp
    src/core/Bot.cpp
    src/core/Physics.cpp
    src/core/AI.cpp
)
target_include_directories(wobs_core PUBLIC src/include)
target_compile_options(wobs_core PRIVATE -Wall -Wextra -Wpedantic -g -Wno-sign-compare)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)

add_executable(wobs_desktop
    src/platform/desktop/main.cpp
)
target_link_libraries(wobs_desktop PRIVATE wobs_core
    ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES}
)
target_include_directories(wobs_desktop PRIVATE
    ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS}
)
target_compile_options(wobs_desktop PRIVATE ${SDL2_CFLAGS_OTHER} -Wall -Wextra -Wpedantic -g -Wno-sign-compare)
