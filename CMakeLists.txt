cmake_minimum_required(VERSION 3.10)
project(digiroyale)

include_directories(include)

add_subdirectory(lib)
add_subdirectory(include)
add_subdirectory(src)

add_library(digiroyale-sim ${DIGIROYALE_SIM_HEADERS} ${DIGIROYALE_SIM_SRC}   "include/digiroyale/simulation/Inventory.hpp" "include/digiroyale/simulation/Survivor.hpp" "src/simulation/Survivor.cpp")

add_executable(digiroyale-bot ${DIGIROYALE_BOT_HEADERS} ${DIGIROYALE_BOT_SRC}   "include/digiroyale/simulation/Inventory.hpp" "include/digiroyale/simulation/Survivor.hpp" "src/simulation/Survivor.cpp")
target_link_libraries(digiroyale-bot digiroyale-sim sleepy-discord)

add_executable(digiroyale-test ${DIGIROYALE_TEST_SRC}   "include/digiroyale/simulation/Inventory.hpp" "include/digiroyale/simulation/Survivor.hpp" "src/simulation/Survivor.cpp")
target_link_libraries(digiroyale-test digiroyale-sim)
