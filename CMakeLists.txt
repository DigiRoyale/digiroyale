cmake_minimum_required(VERSION 3.10)
project(digiroyale)

include_directories(include)

add_subdirectory(lib)
add_subdirectory(include)
add_subdirectory(src)

add_executable(digiroyale ${DIGIROYALE_HEADERS} ${DIGIROYALE_SRC})
target_link_libraries(digiroyale sleepy-discord)
