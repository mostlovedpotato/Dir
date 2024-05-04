# CMakeList.txt : CMake project for DownloadEasy, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (DownloadEasy "DownloadEasy.cpp" "DownloadEasy.h" "src/main.cpp" "src/FileManager.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DownloadEasy PROPERTY CXX_STANDARD 20)
endif()

cmake_minimum_required(VERSION 3.10)
project(DownloadManager)

set(CMAKE_CXX_STANDARD 17)

# Include Boost libraries for networking
find_package(Boost 1.84.0 REQUIRED COMPONENTS system)

# Include directories for header files
include_directories(include)

# Add source files
add_executable(DownloadManager
    src/main.cpp
    src/Downloader.cpp
    src/FileManager.cpp
    src/NetworkManager.cpp
)

# Link with Boost libraries
if(Boost_FOUND)
    target_link_libraries(DownloadManager ${Boost_LIBRARIES})
endif()


# TODO: Add tests and install targets if needed.
