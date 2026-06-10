// Unit tests for twoSumArray and twoSumHashTable.
// Covers normal cases, edge cases (duplicates, negatives, no solution),
// and boundary conditions (empty, single element, first/last pair).
#include <iostream>
#include <string>
#include <vector>

std::vector<int> twoSumArray(const std::vector<int>& nums, int target);
std::vector<int> twoSumHashTable(const std::vector<int>& nums, int target);

static int g_failed = 0;
static int g_passed = 0;

static bool valid_pair(const std::vector<int>& nums, int target,
                       const std::vector<int>& result) {
    if (result.size() != 2) return false;
    int i = result[0], j = result[1];
    if (i == j) return false;
    if (i < 0 || j < 0) return false;
    if (i >= static_cast<int>(nums.size()) || j >= static_cast<int>(nums.size())) return false;
    return nums[i] + nums[j] == target;
}

static void check(const std::string& name, bool condition) {
    if (condition) {
        ++g_passed;
        std::cout << "[ PASS ] " << name << "\n";
    } else {
        ++g_failed;
        std::cout << "[ FAIL ] " << name << "\n";
    }
}

using Fn = std::vector<int> (*)(const std::vector<int>&, int);

static void run_suite(const std::string& impl, Fn fn) {
    // Normal: standard example
    {
        std::vector<int> nums = {2, 7, 11, 15};
        auto r = fn(nums, 9);
        check(impl + " normal: {2,7,11,15} target 9", valid_pair(nums, 9, r));
    }

    // Normal: pair not at the start
    {
        std::vector<int> nums = {3, 2, 4};
        auto r = fn(nums, 6);
        check(impl + " normal: {3,2,4} target 6", valid_pair(nums, 6, r));
    }

    // Edge: duplicates that form the answer
    {
        std::vector<int> nums = {3, 3};
        auto r = fn(nums, 6);
        check(impl + " edge: duplicates {3,3} target 6", valid_pair(nums, 6, r));
    }

    // Edge: duplicates where only specific indices sum
    {
        std::vector<int> nums = {3, 2, 3};
        auto r = fn(nums, 6);
        check(impl + " edge: {3,2,3} target 6", valid_pair(nums, 6, r));
    }

    // Edge: all negative numbers
    {
        std::vector<int> nums = {-1, -2, -3, -4, -5};
        auto r = fn(nums, -8);
        check(impl + " edge: all negatives target -8", valid_pair(nums, -8, r));
    }

    // Edge: mixed signs crossing zero
    {
        std::vector<int> nums = {-3, 4, 3, 90};
        auto r = fn(nums, 0);
        check(impl + " edge: mixed signs target 0", valid_pair(nums, 0, r));
    }

    // Edge: no valid pair -> empty vector
    {
        std::vector<int> nums = {1, 2, 3};
        auto r = fn(nums, 100);
        check(impl + " edge: no solution returns empty", r.empty());
    }

    // Boundary: empty input
    {
        std::vector<int> nums;
        auto r = fn(nums, 0);
        check(impl + " boundary: empty input returns empty", r.empty());
    }

    // Boundary: single element cannot form a pair
    {
        std::vector<int> nums = {5};
        auto r = fn(nums, 5);
        check(impl + " boundary: single element returns empty", r.empty());
    }

    // Boundary: pair is the first two elements
    {
        std::vector<int> nums = {1, 4, 9, 16};
        auto r = fn(nums, 5);
        check(impl + " boundary: first-two pair", valid_pair(nums, 5, r));
    }

    // Boundary: pair is the last two elements
    {
        std::vector<int> nums = {1, 4, 9, 16};
        auto r = fn(nums, 25);
        check(impl + " boundary: last-two pair", valid_pair(nums, 25, r));
    }

    // Boundary: large input, answer at the far end
    {
        std::vector<int> nums(1000);
        for (int i = 0; i < 1000; ++i) nums[i] = i;
        auto r = fn(nums, 1997);  // 998 + 999
        check(impl + " boundary: 1000 elements, far-end pair",
              valid_pair(nums, 1997, r));
    }
}

int main() {
    run_suite("twoSumArray    ", twoSumArray);
    run_suite("twoSumHashTable", twoSumHashTable);

    std::cout << "\n" << g_passed << " passed, " << g_failed << " failed\n";
    return g_failed == 0 ? 0 : 1;
}
