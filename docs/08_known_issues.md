# Known Issues & Limitations

## 1. Known Issues

### Issue 1: Large Array Performance Degradation
**Severity**: Low
**Component**: twoSumArray function
**Description**: For very large arrays (> 100,000 elements), the sorting step may cause noticeable performance degradation.
**Platform**: All
**Impact**: Hash table approach performs better for large datasets.
**Workaround**: Use `twoSumHashTable()` instead for large inputs.
**Status**: Open (by design)

### Issue 2: Integer Overflow with Large Numbers
**Severity**: Medium
**Component**: Both functions
**Description**: When calculating `sum = nums[left] + nums[right]`, integer overflow can occur with values near INT_MAX.
**Platform**: All
**Example**:
```cpp
nums = [INT_MAX - 1, INT_MAX], target = INT_MAX
// May overflow during sum calculation
```
**Impact**: Incorrect results for extreme values
**Workaround**: Use 64-bit integers (long long) for large number ranges
**Status**: Open (potential enhancement)

### Issue 3: Hash Collisions in Edge Cases
**Severity**: Low
**Component**: twoSumHashTable function
**Description**: In rare cases, unordered_map collisions could impact performance.
**Platform**: All
**Impact**: Performance degradation in specific hash distributions
**Workaround**: Use different hash function or different data structure
**Status**: Open (edge case)

## 2. Limitations

### Limitation 1: 32-bit Integer Range
**Description**: Input array limited to 32-bit signed integers (int type)
**Range**: -2,147,483,648 to 2,147,483,647
**Impact**: Cannot handle arbitrary precision numbers
**Workaround**: Modify to use long long for larger range

### Limitation 2: No Custom Comparators
**Description**: Sorting is fixed to ascending order in array approach
**Impact**: Cannot customize sorting behavior
**Workaround**: None currently available

### Limitation 3: Memory Overhead
**Description**: Both algorithms use O(n) additional space
**Impact**: Large arrays consume significant memory
**Example**: For n=1,000,000, additional ~4-8 MB required
**Workaround**: None (algorithmic requirement)

### Limitation 4: Single Pair Return
**Description**: Functions return only the first valid pair found
**Impact**: Multiple solutions not discoverable
**Example**:
```cpp
nums = [1, 2, 3, 4], target = 5
// Returns [0, 3] (indices of 1 and 4)
// Could also be [1, 2] (indices of 2 and 3), but not returned
```
**Workaround**: Modify functions to return all pairs (higher complexity)

## 3. Platform-Specific Considerations

### Windows
**No known issues**

### Linux
**No known issues**

### macOS
**No known issues**

### Note on Compiler Versions
- Minimum GCC: 11.0
- Minimum Clang: 13.0
- Minimum MSVC: 2019

## 4. Future Enhancements

### Enhancement 1: Multiple Pairs Return
**Description**: Return all valid pairs instead of just first one
**Complexity**: Increases algorithm complexity to O(n²) worst case
**Potential Impact**: Significant performance impact for large arrays

### Enhancement 2: Long Long Support
**Description**: Support 64-bit integers for larger number ranges
**Complexity**: Low (simple type change)
**Potential Impact**: None

### Enhancement 3: Custom Comparators
**Description**: Allow custom sorting comparators for array approach
**Complexity**: Medium
**Potential Impact**: Increased flexibility

### Enhancement 4: Avoid Integer Overflow
**Description**: Use 64-bit intermediate calculations to prevent overflow
**Complexity**: Low
**Potential Impact**: Slight performance overhead

### Enhancement 5: Alternative Hash Functions
**Description**: Support choice of hash functions to minimize collisions
**Complexity**: Medium
**Potential Impact**: Better performance in edge cases

## 5. Compatibility Issues

### No Known Compatibility Issues

The code is compatible with:
- ✓ GCC 11+
- ✓ Clang 13+
- ✓ MSVC 2019+
- ✓ C++20 standard
- ✓ Linux, macOS, Windows

## 6. Performance Considerations

### Worst-Case Performance
**Array Approach:**
- Time: O(n log n)
- Input: [1, 2, 3, ..., n]
- Effect: Full sort required, no early termination

**Hash Table Approach:**
- Time: O(1) each for n elements = O(n) total
- No worst case degradation (average case = worst case)

### Best-Case Performance
**Array Approach:**
- Time: O(n log n) (always sorts)
- Pair found early during two-pointer phase

**Hash Table Approach:**
- Time: O(1) if first two elements sum to target
- O(n) guaranteed for any input

## 7. Testing Gaps

### Not Tested
- [ ] Very large arrays (> 100 million elements)
- [ ] Concurrent access (no thread safety implemented)
- [ ] Shared memory scenarios
- [ ] Real-time systems with strict timing requirements

### Not Implemented
- Thread safety
- Custom memory allocation
- Streaming/online algorithms
- Parallelization

## 8. Documentation Issues

### No Known Documentation Issues
All documentation is current and accurate as of March 26, 2026.

## 9. Workarounds Summary

| Issue | Workaround | Difficulty |
|-------|-----------|-----------|
| Integer Overflow | Use long long instead of int | Easy |
| Large Array Overhead | Use hash table approach | N/A |
| Multiple Pairs Needed | Modify function logic | Medium |
| Hash Collisions | Use different data structure | Medium |

## 10. Reporting Issues

If you discover an issue not listed here:

1. **Description**: Clearly describe the problem
2. **Reproduction Steps**: Provide steps to reproduce
3. **Platform**: OS, compiler, compiler version
4. **Code Example**: Minimal reproducible example
5. **Expected vs Actual**: What should happen vs what happens

**Report to**: GitHub Issues at https://github.com/RyuuNesta/11402_CS351_Project0/issues

## 11. Version History

### Version 1.0 (March 26, 2026)
- Initial release
- Two implementations (array and hash table)
- Comprehensive documentation
- Test suite with 6 test cases

### Known Issues in 1.0
- Integer overflow with extreme values (tracked above)
- No support for 64-bit integers
