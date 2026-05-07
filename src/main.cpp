#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// Function declarations
std::vector<int> twoSumArray(const std::vector<int>& nums, int target);
std::vector<int> twoSumHashTable(const std::vector<int>& nums, int target);

struct TestCase {
    std::string name;
    std::vector<int> nums;
    int target;
    bool expectValidPair;
};

bool isValidTwoSumResult(const std::vector<int>& nums, int target, const std::vector<int>& result, bool expectValidPair) {
    if (result.empty()) {
        return !expectValidPair;
    }

    if (result.size() != 2) {
        return false;
    }

    int i0 = result[0];
    int i1 = result[1];
    if (i0 < 0 || i1 < 0 || i0 >= static_cast<int>(nums.size()) || i1 >= static_cast<int>(nums.size())) {
        return false;
    }

    if (i0 == i1) {
        return false;
    }

    if (nums[i0] + nums[i1] != target) {
        return false;
    }

    if (i0 > i1) {
        return false;
    }

    return true;
}

void printResult(const std::string& method, const std::vector<int>& nums, int target, const std::vector<int>& result, bool expectValidPair) {
    std::cout << method << " - Input: [";
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        std::cout << nums[i];
        if (i < static_cast<int>(nums.size()) - 1) std::cout << ", ";
    }
    std::cout << "], Target: " << target << " -> ";

    if (result.empty()) {
        std::cout << "No pair found";
    } else {
        std::cout << "[" << result[0] << ", " << result[1] << "]";
        std::cout << " (values: " << nums[result[0]] << " + " << nums[result[1]] << " = "
                  << (nums[result[0]] + nums[result[1]]) << ")";
    }

    bool passed = isValidTwoSumResult(nums, target, result, expectValidPair);
    std::cout << " -> " << (passed ? "PASS" : "FAIL") << std::endl;
}

int main() {
    std::cout << "=== Two Sum Problem - C++20 Implementation ===" << std::endl << std::endl;

    std::vector<TestCase> tests = {
        {"Basic case", {2, 7, 11, 15}, 9, true},
        {"Multiple valid pairs", {1, 2, 3, 2}, 4, true},
        {"Duplicate values", {3, 3}, 6, true},
        {"Negative numbers", {-3, 4, 3, 90}, 0, true},
        {"Zero and negative values", {-1, 0, 1, 2, -1, -4}, 0, true},
        {"Zero pair with duplicates", {0, 0, 4, 5}, 0, true},
        {"Negative target", {-5, -2, 3, 6}, -7, true},
        {"All negative numbers", {-5, -4, -3, -2}, -9, true},
        {"Two-element valid pair", {1, 1}, 2, true},
        {"Mixed pos/neg zero target", {-5, 5}, 0, true},
        {"No valid pair", {1, 2, 3}, 7, false},
        {"Empty array", {}, 5, false},
        {"Single element", {5}, 5, false},
        {"Large numbers", {1000000, 2000000, 3000000}, 5000000, true}
    };

    int passedCount = 0;
    int totalCount = 0;

    for (const auto& test : tests) {
        std::cout << "Test: " << test.name << std::endl;
        auto arrayResult = twoSumArray(test.nums, test.target);
        auto hashResult = twoSumHashTable(test.nums, test.target);

        printResult("  Array Approach", test.nums, test.target, arrayResult, test.expectValidPair);
        printResult("  Hash Table Approach", test.nums, test.target, hashResult, test.expectValidPair);
        std::cout << std::endl;

        if (isValidTwoSumResult(test.nums, test.target, arrayResult, test.expectValidPair)) {
            ++passedCount;
        }
        if (isValidTwoSumResult(test.nums, test.target, hashResult, test.expectValidPair)) {
            ++passedCount;
        }
        totalCount += 2;
    }

    std::cout << "Summary: " << passedCount << " / " << totalCount << " tests passed" << std::endl;
    return (passedCount == totalCount ? 0 : 1);
}
