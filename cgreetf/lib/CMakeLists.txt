add_library(greetings STATIC greetings.c)
target_include_directories(greetings PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
