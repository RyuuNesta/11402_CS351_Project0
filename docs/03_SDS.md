# Software Design Specification (SDS)

## 1. Architecture Overview

```
┌─────────────────────────────────────┐
│         Main Program                │
│        (main.cpp)                   │
│  - Test cases                       │
│  - Result output                    │
└────────┬────────────┬───────────────┘
         │            │
         ▼            ▼
┌──────────────────────────────────┐
│    Algorithm Implementations     │
│      (twosum.cpp)                │
├──────────────────────────────────┤
│ twoSumArray()    │  twoSumHashTable()
│ - Sorting        │  - Hash map
│ - Two pointers   │  - Single pass
└──────────────────────────────────┘
```

## 2. Component Design

### 2.1 twoSumArray() Function

**Algorithm**: Sort + Two Pointers

**Pseudocode**:
```
1. Create (value, index) pairs to track original indices
2. Sort pairs by value
3. Initialize left = 0, right = n-1
4. While left < right:
   a. Calculate sum = sorted_array[left] + sorted_array[right]
   b. If sum == target: return [left_original_index, right_original_index]
   c. If sum < target: left++
   d. If sum > target: right--
5. Return empty vector (no solution found)
```

**Complexity**:
- Time: O(n log n) - dominated by sorting
- Space: O(n) - for storing indexed pairs

### 2.2 twoSumHashTable() Function

**Algorithm**: Hash Table (Single Pass)

**Pseudocode**:
```
1. Create empty hash map (value -> index)
2. For each element nums[i]:
   a. Calculate complement = target - nums[i]
   b. If complement exists in map:
      - Return [map[complement], i]
   c. Otherwise: map[nums[i]] = i
3. Return empty vector (no solution found)
```

**Complexity**:
- Time: O(n) - single pass through array
- Space: O(n) - for hash map

### 2.3 Main Program

**Flow**:
1. Initialize test cases with different scenarios
2. Call both algorithms for each test case
3. Print formatted results with verification

**Test Cases**:
- Basic case: [2, 7, 11, 15], target=9
- Negative numbers: [-3, 4, 3, 90], target=0
- Duplicates: [3, 3, 4], target=6
- No solution: [1, 2, 3], target=10
- Zeros: [-1, 0, 1, 2, -1, -4], target=0
- Large numbers: [1000000, 2000000, 3000000], target=3000000

## 3. Data Structures

### Input Data
```cpp
std::vector<int> nums          // Array of integers
int target                      // Target sum value
```

### Output Data
```cpp
std::vector<int> result         // Two indices [i, j] where i < j
// Empty vector if no valid pair exists
```

### Internal Data Structures
- Array approach: `std::vector<std::pair<int, int>>` for (value, index) pairs
- Hash table approach: `std::unordered_map<int, int>` for value -> index mapping

## 4. Design Decisions

### Decision 1: Return Type
**Choice**: Return `std::vector<int>` with either 2 elements or empty
**Rationale**: Simple, clear semantics - caller can check if vector is empty

**Alternative**: Return `std::optional<std::pair<int, int>>`
**Why Not**: Less compatible, requires C++17

### Decision 2: Index Ordering
**Choice**: Always return smaller index first [i, j] where i < j
**Rationale**: Consistent output format, matches expected output format

### Decision 3: Sorting Implementation
**Choice**: Use `std::sort` with pairs to track indices
**Rationale**: Standard library optimal sorting, preserves original indices cleanly

### Decision 4: Hash Table Implementation
**Choice**: Use `std::unordered_map<int, int>`
**Rationale**: Average O(1) lookup, simple API, standard library

## 5. Class/Function Interfaces

### Function: twoSumArray
```cpp
std::vector<int> twoSumArray(const std::vector<int>& nums, int target);
```
- Precondition: nums is valid vector
- Postcondition: Returns indices or empty vector
- No side effects

### Function: twoSumHashTable
```cpp
std::vector<int> twoSumHashTable(const std::vector<int>& nums, int target);
```
- Precondition: nums is valid vector
- Postcondition: Returns indices or empty vector
- No side effects

## 6. Error Handling

## Error Cases
- Empty input array → Return empty vector
- No valid pair exists → Return empty vector
- Array with single element → Return empty vector

**Strategy**: Return empty vector to indicate no solution found
**Rationale**: Simple, caller can check with `result.empty()`

## 7. Performance Considerations

### Array Approach
- Advantage: Predictable O(n log n) performance
- Disadvantage: Requires sorting, more memory for pairs

### Hash Table Approach
- Advantage: Optimal O(n) time for most cases
- Disadvantage: Potential hash collisions, higher constant factors

**Recommendation**: Use hash table for production code when optimal time is priority
