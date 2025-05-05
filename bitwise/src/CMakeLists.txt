# Main binary
add_library(bitops STATIC ${CMAKE_SOURCE_DIR}/include/bitops.cpp)
target_include_directories(bitops PUBLIC ${CMAKE_SOURCE_DIR}/include)
add_executable(bitwise bitwise.cpp)
target_link_libraries(bitwise PRIVATE bitops)

# Adding as library for testing
set(SRC_FILES bitwise.cpp)
add_library(bitwise_lib ${SRC_FILES})
target_include_directories(bitwise_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Single function binaries
add_executable(hamming hamming.cpp)
add_library(hamming_lib STATIC ${CMAKE_SOURCE_DIR}/src/hamming.cpp)
add_executable(kbit kbit.cpp)
add_executable(kflip kflip.cpp)
add_executable(powtwo powtwo.cpp)
add_executable(swap swap.cpp)
