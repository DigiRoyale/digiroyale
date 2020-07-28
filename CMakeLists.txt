cmake_minimum_required(VERSION 3.10)
project(digiroyale)

include_directories(include)

add_subdirectory(lib)
add_subdirectory(include)
add_subdirectory(src)

add_library(digiroyale-sim ${DIGIROYALE_SIM_HEADERS} ${DIGIROYALE_SIM_SRC})

add_executable(digiroyale-bot ${DIGIROYALE_BOT_HEADERS} ${DIGIROYALE_BOT_SRC})
target_link_libraries(digiroyale-bot digiroyale-sim sleepy-discord)
