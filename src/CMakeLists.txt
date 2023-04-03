add_library(MissingNumbers)

target_sources(MissingNumbers PRIVATE MissingNumbers.cpp PUBLIC MissingNumbers.h)
target_include_directories(MissingNumbers PUBLIC ${CMAKE_CURRENT_LIST_DIR})
