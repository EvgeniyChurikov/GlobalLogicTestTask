#include <gtest/gtest.h>
#include <fstream>
#include "MissingNumbers.h"

std::vector<std::tuple<int, int, std::vector<int>>> read_tests_from_file() {
    std::vector<std::tuple<int, int, std::vector<int>>> tests{};
    std::ifstream file("tests.txt");
    int k, n;
    while (file >> k >> n) {
        std::vector<int> arr(k - 2);
        for (int i = 0; i < k - 2; ++i) {
            file >> arr[i];
        }
        tests.emplace_back(k, n, arr);
    }
    file.close();
    return tests;
}

class MissingNumbersTests : public testing::TestWithParam<std::tuple<int, int, std::vector<int>>> {};

TEST_P(MissingNumbersTests, missing_numbers_1) {
    auto [K, n, arr] = GetParam();
    ASSERT_EQ(missing_numbers_1(K, arr.data()), n);
}

TEST_P(MissingNumbersTests, missing_numbers_2) {
    auto [K, n, arr] = GetParam();
    ASSERT_EQ(missing_numbers_2(K, arr.data()), n);
}

TEST_P(MissingNumbersTests, missing_numbers_3) {
    auto [K, n, arr] = GetParam();
    ASSERT_EQ(missing_numbers_3(K, arr.data()), n);
}

INSTANTIATE_TEST_SUITE_P(
        TestsFromFile,
        MissingNumbersTests,
        testing::ValuesIn(read_tests_from_file()));
