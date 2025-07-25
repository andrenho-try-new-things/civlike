cmake_minimum_required(VERSION 3.17)
project(civlike
        VERSION 0.1
        LANGUAGES C CXX ASM)

set_property(GLOBAL PROPERTY C_STANDARD 11)
set_property(GLOBAL PROPERTY CXX_STANDARD 23)

# Adding Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

FetchContent_Declare(
        raylib
        GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
        GIT_TAG "master"
        GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)

# project
set(PROJECT_SOURCES
        main.cc
)

add_executable(${PROJECT_NAME}
        rules/game_rules.hh
        rules/game_rules.cc
        sample/sample_game.cc
        sample/sample_game.hh
        game/game.cc
        game/game.hh
        game/tile.hh
        rules/id.hh
        ui/graphics.cc
        ui/graphics.hh
)
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE .)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wno-sign-compare)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)