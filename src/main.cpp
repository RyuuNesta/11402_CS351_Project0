#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// Function declarations
std::vector<int> twoSumArray(const std::vector<int>& nums, int target);
std::vector<int> twoSumHashTable(const std::vector<int>& nums, int target);

// Helper function to print results
void printResult(const std::string& method, const std::vector<int>& nums, int target, const std::vector<int>& result) {
    std::cout << method << " - Input: [";
    for (int i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i < nums.size() - 1) std::cout << ", ";
    }
    std::cout << "], Target: " << target << " -> ";
    
    if (result.empty()) {
        std::cout << "No pair found" << std::endl;
    } else {
        std::cout << "[" << result[0] << ", " << result[1] << "]";
        std::cout << " (values: " << nums[result[0]] << " + " << nums[result[1]] << " = " 
                  << (nums[result[0]] + nums[result[1]]) << ")" << std::endl;
    }
}

int main() {
    std::cout << "=== Two Sum Problem - C++20 Implementation ===" << std::endl << std::endl;
    
    // Test Case 1: Basic case
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::cout << "Test 1: Basic case" << std::endl;
    printResult("  Array Approach", nums1, target1, twoSumArray(nums1, target1));
    printResult("  Hash Table Approach", nums1, target1, twoSumHashTable(nums1, target1));
    std::cout << std::endl;
    
    // Test Case 2: Negative numbers
    std::vector<int> nums2 = {-3, 4, 3, 90};
    int target2 = 0;
    std::cout << "Test 2: Negative numbers" << std::endl;
    printResult("  Array Approach", nums2, target2, twoSumArray(nums2, target2));
    printResult("  Hash Table Approach", nums2, target2, twoSumHashTable(nums2, target2));
    std::cout << std::endl;
    
    // Test Case 3: Duplicate values
    std::vector<int> nums3 = {3, 3, 4};
    int target3 = 6;
    std::cout << "Test 3: Duplicate values" << std::endl;
    printResult("  Array Approach", nums3, target3, twoSumArray(nums3, target3));
    printResult("  Hash Table Approach", nums3, target3, twoSumHashTable(nums3, target3));
    std::cout << std::endl;
    
    // Test Case 4: No valid pair
    std::vector<int> nums4 = {1, 2, 3};
    int target4 = 10;
    std::cout << "Test 4: No valid pair" << std::endl;
    printResult("  Array Approach", nums4, target4, twoSumArray(nums4, target4));
    printResult("  Hash Table Approach", nums4, target4, twoSumHashTable(nums4, target4));
    std::cout << std::endl;
    
    // Test Case 5: Zero value
    std::vector<int> nums5 = {-1, 0, 1, 2, -1, -4};
    int target5 = 0;
    std::cout << "Test 5: Zero value and negatives" << std::endl;
    printResult("  Array Approach", nums5, target5, twoSumArray(nums5, target5));
    printResult("  Hash Table Approach", nums5, target5, twoSumHashTable(nums5, target5));
    std::cout << std::endl;
    
    // Test Case 6: Large numbers
    std::vector<int> nums6 = {1000000, 2000000, 3000000};
    int target6 = 3000000;
    std::cout << "Test 6: Large numbers" << std::endl;
    printResult("  Array Approach", nums6, target6, twoSumArray(nums6, target6));
    printResult("  Hash Table Approach", nums6, target6, twoSumHashTable(nums6, target6));
    std::cout << std::endl;
    
    return 0;
}