cmake_minimum_required (VERSION 3.0.0)
project (main CXX)

cmake_minimum_required (VERSION 3.0.0)
project (musicfy VERSION 0.1 LANGUAGES CXX)

include_directories(include)

add_executable( program
                src/main_test.cpp
                src/Music.cpp
                src/Playlist.cpp
                src/Split.cpp)