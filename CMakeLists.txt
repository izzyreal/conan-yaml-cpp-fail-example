cmake_minimum_required(VERSION 2.8.12)
project(conan-yaml-cpp-fail-example)

add_definitions("-std=c++17")

set(_src_root_path "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(_resources_root_path "${CMAKE_CURRENT_SOURCE_DIR}/resources")
include_directories( ${_src_root_path})

file(
    GLOB_RECURSE _source_list
    LIST_DIRECTORIES false
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "${_src_root_path}/*.cpp*"
    "${_src_root_path}/*.hpp*"
    "${_resources_root_path}/*.yaml*"
)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(conan-yaml-cpp-fail-example ${_source_list})
target_link_libraries(conan-yaml-cpp-fail-example ${CONAN_LIBS})

foreach(_source IN ITEMS ${_source_list})
    get_filename_component(_source_path "${_source}" PATH)
    string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
    source_group("${_source_path_msvc}" FILES "${_source}")
endforeach()

add_custom_command(
    TARGET conan-yaml-cpp-fail-example POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${_resources_root_path}/test.yaml
    ${CMAKE_CURRENT_BINARY_DIR}/bin/test.yaml
)
