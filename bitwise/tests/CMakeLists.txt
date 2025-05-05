include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)


FetchContent_MakeAvailable(googletest)


enable_testing()


function(add_my_test name sources)
    # Define executable
    add_executable(${name} ${sources})
    # Add includes
    target_include_directories(${name} PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)
    # Link libraries, always include gtest
    target_link_libraries(${name}
        PRIVATE
            GTest::gtest 
            GTest::gtest_main
            ${ARGN}
    )
    add_test(NAME ${name} COMMAND ${name})
    set_target_properties(${name} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests/bin
    )

endfunction()


add_my_test(SwapTest test_swap.cpp bitops)
add_my_test(PowtwoTest test_powtwo.cpp bitops)
add_my_test(HammingTest test_hamming.cpp bitops)
add_my_test(KBitTest test_kbit.cpp bitops)
add_my_test(KFlipTest test_kflip.cpp bitops)
add_my_test(BitwiseTest test_bitwise.cpp bitwise_lib)
target_compile_definitions(BitwiseTest PRIVATE BINARY_PATH="${CMAKE_SOURCE_DIR}/bin/bitwise")
#add_my_test(HammingBin test_hamming_bin.cpp)
