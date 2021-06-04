add_custom_target("uninstall")
set_target_properties("uninstall" PROPERTIES FOLDER "CMakePredefinedTargets")

option(BUILD_SHARED_LIBS "" OFF)

############# EntityX #############
option(ENTITYX_BUILD_SHARED "" OFF)
option(ENTITYX_BUILD_TESTING "" OFF)

add_external_tar("alecthomas-entityx-82ab2d3" "https://codeload.github.com/alecthomas/entityx/legacy.tar.gz/82ab2d304ef5e6933cf6622721f086a1f4731e80" "")

target_include_directories("entityx" PUBLIC
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/alecthomas-entityx-82ab2d3>"
	"$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/alecthomas-entityx-82ab2d3"
)

set_target_properties("entityx" PROPERTIES FOLDER "Thirdparty")

############# GLM #############
option(GLM_STATIC_LIBRARY_ENABLE "" ON)

add_external_zip("glm" "https://github.com/g-truc/glm/releases/download/0.9.9.8/glm-0.9.9.8.zip" "")

set_target_properties("glm" PROPERTIES FOLDER "Thirdparty")

############# Assimp #############
option(ASSIMP_BUILD_TESTS "" OFF)
option(ASSIMP_BUILD_SAMPLES "" OFF)

add_external_tar("assimp-5.0.1" "https://github.com/assimp/assimp/archive/refs/tags/v5.0.1.tar.gz" "")

target_include_directories("assimp" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/assimp-5.0.1/include")

set_target_properties("assimp" PROPERTIES FOLDER "Thirdparty")
set_target_properties("assimp_cmd" PROPERTIES FOLDER "Thirdparty")
set_target_properties("IrrXML" PROPERTIES FOLDER "Thirdparty")
set_target_properties("UpdateAssimpLibsDebugSymbolsAndDLLs" PROPERTIES FOLDER "Thirdparty")
set_target_properties("zlib" PROPERTIES FOLDER "Thirdparty")
set_target_properties("zlibstatic" PROPERTIES FOLDER "Thirdparty")

target_compile_options("assimp" PUBLIC "/wd4996")
target_compile_options("assimp" PUBLIC "/wd4700")