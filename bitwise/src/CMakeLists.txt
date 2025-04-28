# Main binary
add_library(bitops STATIC ${CMAKE_SOURCE_DIR}/include/bitops.cpp)
target_include_directories(bitops PUBLIC ${CMAKE_SOURCE_DIR}/include)
add_executable(bitwise bitwise.cpp)
target_link_libraries(bitwise PRIVATE bitops)

# Single function binaries
add_executable(hamming hamming.cpp)
add_library(hamming_lib STATIC ${CMAKE_SOURCE_DIR}/src/hamming.cpp)
add_executable(kbit kbit.cpp)
add_executable(kflip kflip.cpp)
add_executable(powtwo powtwo.cpp)
add_executable(swap swap.cpp)
