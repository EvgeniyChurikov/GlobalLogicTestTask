include(FetchContent)
FetchContent_Declare(gtest
        QUIET
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.tar.gz
        )
FetchContent_MakeAvailable(gtest)

add_executable(unit_tests MissingNumbersTests.cpp)
target_link_libraries(unit_tests PRIVATE MissingNumbers gtest_main)
