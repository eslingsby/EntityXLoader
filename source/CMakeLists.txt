file(GLOB_RECURSE src "*.hpp" "*.cpp")

add_executable("Source" "${src}")

target_include_directories("Source" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries("Source" "entityx")
target_link_libraries("Source" "glm")
target_link_libraries("Source" "assimp")