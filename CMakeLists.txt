cmake_minimum_required(VERSION 3.27)
project(base_raylib_game_project CXX)

set(CMAKE_CXX_STANDARD 17)

set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()


include_directories(./ext/imgui)
include_directories(./ext/rlImgui)
include_directories(./inc)

file(GLOB IMGUI_FILES ./ext/imgui/*.h ./ext/imgui/*.cpp)
file(GLOB RLIMGUI_FILES ./ext/rlImgui/*.h ./ext/rlImgui/*.cpp)
file(GLOB SRC_FILES ./src/*.cpp ./src/**/*.cpp)
file(GLOB INC_FILES ./src/*.h ./src/**/*.h)

file(COPY ${STEAM_SHIT} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(base_raylib_game_project ${IMGUI_FILES} ${RLIMGUI_FILES} ${SRC_FILES} ${INC_FILES})
target_link_libraries(base_raylib_game_project raylib)
