#include <vector>
#include <unordered_map>

// Brute-force approach using nested loops
// Time: O(n^2)
// Space: O(1)
std::vector<int> twoSumArray(const std::vector<int>& nums, int target) {
    int n = static_cast<int>(nums.size());

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    // No valid pair found
    return {};
}

// Hash table approach
// Time: O(n)
// Space: O(n) for the hash table
std::vector<int> twoSumHashTable(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> value_to_index;
    
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int complement = target - nums[i];
        
        // Check if complement exists in the map
        if (value_to_index.find(complement) != value_to_index.end()) {
            // Return indices with smaller index first
            int first_idx = value_to_index[complement];
            int second_idx = i;
            if (first_idx > second_idx) {
                return {second_idx, first_idx};
            }
            return {first_idx, second_idx};
        }
        
        // Store current value and its index
        value_to_index[nums[i]] = i;
    }
    
    // No valid pair found
    return {};
}