cmake_minimum_required(VERSION "3.7.1")

project("EPITECH_JAM")

set(SOURCES
    src/main.cpp
    src/SceneManager.cpp
    src/gameloop/MenuGameLoop.cpp
    src/gameloop/MenuEndGameLoop.cpp
    src/gameloop/HtpGameLoop.cpp
    src/gameloop/PlayGameLoop.cpp
)

find_package(SFML COMPONENTS graphics window REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    PUBLIC 
    sfml-graphics 
    sfml-audio)

target_include_directories(${PROJECT_NAME}
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/class
)
