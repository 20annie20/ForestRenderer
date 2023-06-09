cmake_minimum_required (VERSION 3.16)

# Policies.
set (CMAKE_POLICY_DEFAULT_CMP0077 NEW) # Enable overriding options with variables.

# Setup build environment.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set (X_VCPKG_APPLOCAL_DEPS_INSTALL ON)
set (CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/External/vcpkg/scripts/buildsystems/vcpkg.cmake")
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake" ${CMAKE_MODULE_PATH})

# Include additional modules.
include (fr_find_sources)

project (ForestRenderer)
set(CMAKE_GENERATOR_PLATFORM Win32)

set (FR_SOURCE_DIR "${CMAKE_SOURCE_DIR}/Src")

# Build engine.
fr_find_sources (FR_SOURCES ${FR_SOURCE_DIR})
source_group (TREE ${FR_SOURCE_DIR} FILES ${FR_SOURCES})

add_executable (forest_renderer ${FR_SOURCES})

target_compile_features (forest_renderer PUBLIC cxx_std_20)

# SDL
message("Setting up SDL...")
find_package(SDL2 CONFIG REQUIRED)

target_link_libraries(forest_renderer
    PRIVATE
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>)

# ImGUI
set(sources
    External/ImGUI/imconfig.h
    External/ImGUI/imgui.cpp
    External/ImGUI/imgui.h
    External/ImGUI/imgui_demo.cpp
    External/ImGUI/imgui_draw.cpp
    External/ImGUI/imgui_internal.h
    External/ImGUI/imgui_tables.cpp
    External/ImGUI/imgui_widgets.cpp
    External/ImGUI/imstb_rectpack.h
    External/ImGUI/imstb_textedit.h
    External/ImGUI/imstb_truetype.h
    External/ImGUI/backends/imgui_impl_sdl2.cpp
    External/ImGUI/backends/imgui_impl_sdl2.h
    External/ImGUI/backends/imgui_impl_sdlrenderer.h
    External/ImGUI/backends/imgui_impl_sdlrenderer.cpp
)

add_library(ImGUI ${sources})
target_include_directories (ImGUI
  PUBLIC "${CMAKE_SOURCE_DIR}/External/ImGUI"
)

target_link_libraries(ImGUI
    PRIVATE
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>)

target_link_libraries(forest_renderer
    PRIVATE ImGUI)

target_include_directories (forest_renderer
  PUBLIC "${CMAKE_SOURCE_DIR}/Src"
  PUBLIC "${CMAKE_SOURCE_DIR}/External/ImGUI"
  PUBLIC "${CMAKE_SOURCE_DIR}/External/ImGUI/backends"
)