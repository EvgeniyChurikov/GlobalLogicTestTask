#include "MissingNumbers.h"

int missing_numbers_1(int K, const int arr[]) {
    int sum = 3;    // 1 + 2
    for (int i = 0; i < K - 2; ++i) {
        sum += i + 3 - arr[i];
    }
    return (sum - 1) / 2;   // sum = n + (n + 1) => n = (sum - 2) / 2
}

int missing_numbers_2(int K, const int arr[]) {
    bool tmp[K];
    for (int i = 0; i < K; ++i) {
        tmp[i] = false;
    }
    for (int i = 0; i < K - 2; ++i) {
        tmp[arr[i] - 1] = true;
    }
    for (int i = 0; i < K; ++i) {
        if (!tmp[i])
            return i + 1;
    }
    return 0;
}

int missing_numbers_3(int K, const int arr[]) {
    for (int n = 1; n <= K; ++n) {
        bool n_not_found = true;
        for (int i = 0; i < K - 2; ++i) {
            if (arr[i] == n) {
                n_not_found = false;
                break;
            }
        }
        if (n_not_found)
            return n;
    }
    return 0;
}
