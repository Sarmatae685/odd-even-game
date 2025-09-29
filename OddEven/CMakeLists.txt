cmake_minimum_required(VERSION 3.16)
project(OddEven_Game)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# .cpp files
set(SOURCES
    src/main.cpp
    src/Display.cpp
    src/Player.cpp
    src/Array2D.cpp
    src/MyGame.cpp
    src/utils.cpp
)

# .h files
set(HEADERS
    src/Display.h
    src/Player.h
    src/Array2D.h
    src/MyGame.h
    src/utils.h
)

add_executable(OddEven ${SOURCES} ${HEADERS})
