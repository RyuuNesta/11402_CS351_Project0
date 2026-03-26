# Test Plan

## 1. Testing Strategy

### Test Levels
- **Unit Testing**: Test each function individually
- **Integration Testing**: Test functions together in main program
- **System Testing**: Test complete program with all combinations

### Testing Approach
- Black-box testing: Test based on requirements, not implementation
- Coverage-based: Ensure all code paths executed

## 2. Test Cases

### TC1: Basic Valid Pair
**ID**: TC1
**Input**: nums = [2, 7, 11, 15], target = 9
**Expected Output**: [0, 1]
**Rationale**: Straightforward case with unique solution
**Function**: Both twoSumArray and twoSumHashTable

### TC2: Negative Numbers
**ID**: TC2
**Input**: nums = [-3, 4, 3, 90], target = 0
**Expected Output**: [0, 1] (indices of -3 and 3)
**Rationale**: Verify handling of negative values
**Function**: Both implementations

### TC3: Duplicate Values in Array
**ID**: TC3
**Input**: nums = [3, 3, 4], target = 6
**Expected Output**: [0, 1]
**Rationale**: Array contains duplicate values
**Function**: Both implementations

### TC4: No Valid Pair Exists
**ID**: TC4
**Input**: nums = [1, 2, 3], target = 10
**Expected Output**: [] (empty vector)
**Rationale**: No two elements sum to target
**Function**: Both implementations

### TC5: Includes Zero Values
**ID**: TC5
**Input**: nums = [-1, 0, 1, 2, -1, -4], target = 0
**Expected Output**: [0, 2] (indices of -1 and 1)
**Rationale**: Array contains zeros and negative numbers
**Function**: Both implementations

### TC6: Large Numbers
**ID**: TC6
**Input**: nums = [1000000, 2000000, 3000000], target = 3000000
**Expected Output**: [0, 1]
**Rationale**: Verify handling of large integer values
**Function**: Both implementations

### TC7: Single Element Array
**ID**: TC7
**Input**: nums = [5], target = 10
**Expected Output**: [] (empty vector)
**Rationale**: Cannot find two numbers in single-element array
**Function**: Both implementations

### TC8: Empty Array
**ID**: TC8
**Input**: nums = [], target = 5
**Expected Output**: [] (empty vector)
**Rationale**: No elements to sum
**Function**: Both implementations

### TC9: Negative Target
**ID**: TC9
**Input**: nums = [-5, -2, 3, 6], target = -7
**Expected Output**: [0, 1] (indices of -5 and -2)
**Rationale**: Target can be negative
**Function**: Both implementations

### TC10: All Negative Numbers
**ID**: TC10
**Input**: nums = [-5, -4, -3, -2], target = -9
**Expected Output**: [0, 2] (indices of -5 and -4)
**Rationale**: All values are negative
**Function**: Both implementations

## 3. Test Results Template

### Test Execution Report
```
Test Case ID: TCX
Function: twoSumArray / twoSumHashTable
Input: nums = [...], target = ...
Expected Output: [...]
Actual Output: [...]
Status: PASS / FAIL
Notes: ...
```

## 4. Performance Testing

### Test Environment
- Compiler: GCC 11+ / Clang 13+ / MSVC 2019+
- Language Standard: C++20
- Optimization: -O2

### Performance Metrics

#### Array Approach
- **Complexity**: O(n log n)
- **Expected**: For n=10,000, should complete in < 1ms

#### Hash Table Approach
- **Complexity**: O(n)
- **Expected**: For n=10,000, should complete in < 0.5ms

## 5. Edge Cases

| Case ID | Description | Input | Expected |
|---------|-------------|-------|----------|
| EC1 | Array size 2, valid pair | [1, 1], target=2 | [0, 1] |
| EC2 | Large target | [1, 2], target=1000000 | [] |
| EC3 | Mixed pos/neg, zero target | [-5, 5], target=0 | [0, 1] |
| EC4 | Multiple valid pairs | [1, 2, 3, 4], target=5 | [0, 3] or [1, 2] |

## 6. Test Execution Procedure

1. Compile code with `-Wall -Wextra -std=c++20`
2. Run executable and observe output
3. Compare actual output with expected results
4. Document test results
5. Report any failures with detailed information

## 7. Pass/Fail Criteria

**Test PASSES if**:
- Output matches expected value exactly
- Indices are in ascending order
- No compilation warnings
- Program runs without crashes

**Test FAILS if**:
- Output differs from expected value
- Indices not in proper order
- Program crashes
- Compilation warnings occur
