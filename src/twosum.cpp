#include <vector>
#include <unordered_map>
#include <algorithm>

// Two-pointer approach on sorted array
// Time: O(n log n) due to sorting
// Space: O(n) for the index pairs vector
std::vector<int> twoSumArray(const std::vector<int>& nums, int target) {
    int n = nums.size();
    
    // Create pairs of (value, original_index)
    std::vector<std::pair<int, int>> indexed_nums(n);
    for (int i = 0; i < n; ++i) {
        indexed_nums[i] = {nums[i], i};
    }
    
    // Sort by value
    std::sort(indexed_nums.begin(), indexed_nums.end());
    
    // Two-pointer approach
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = indexed_nums[left].first + indexed_nums[right].first;
        
        if (sum == target) {
            // Return original indices (0-based)
            std::vector<int> result = {indexed_nums[left].second, indexed_nums[right].second};
            // Ensure smaller index comes first
            if (result[0] > result[1]) {
                std::swap(result[0], result[1]);
            }
            return result;
        }
        else if (sum < target) {
            ++left;
        }
        else {
            --right;
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
    
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        
        // Check if complement exists in the map
        if (value_to_index.find(complement) != value_to_index.end()) {
            // Return indices with smaller index first
            int first_idx = value_to_index[complement];
            int second_idx = i;
            if (first_idx > second_idx) {
                std::swap(first_idx, second_idx);
            }
            return {first_idx, second_idx};
        }
        
        // Store current value and its index
        value_to_index[nums[i]] = i;
    }
    
    // No valid pair found
    return {};
}