# CMakeList.txt : CMake project for Test, include source and define
# project specific logic here.
#

target_include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src" "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
message(STATUS "Project source directory: ${PROJECT_SOURCE_DIR}")


# Add source to this project's executable.
add_executable (Test "Test.cpp" "src/FileManager.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Test PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
