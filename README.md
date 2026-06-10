## Two Sum

Two Sum is a classic LeetCode algorithm problem where you need to find two numbers in an array that add up to a target value. Given an array of integers and a target sum, return the indices of the two numbers that sum to the target.

### Requirements

#### 1. Programming Language
- **C++ 20** with STL vector

#### 2. Implementations
Two different approaches are required:

##### TwoSumArray
- Brute force nested-loop approach
- Time Complexity: O(n^2)
- Space Complexity: O(1)

##### TwoSumHashTable
- Hash map/unordered_map approach
- Time Complexity: O(n) average-case
- Space Complexity: O(n)

#### 3. Test Cases
Comprehensive unit tests covering:
- Basic cases with valid pairs
- Cases with duplicate numbers
- Cases where no pair exists
- Edge cases (empty array, single element)
- Multiple valid pairs
- Negative numbers
- Zero values
- Boundary conditions with large numbers

##### Example coverage
- Normal case: `[2, 7, 11, 15]`, target `9`
- Multiple valid pairs: `[1, 2, 3, 2]`, target `4`
- Duplicate values: `[3, 3]`, target `6`
- Negative numbers: `[-3, 4, 3, 90]`, target `0`
- Zero values and negatives: `[-1, 0, 1, 2, -1, -4]`, target `0`
- No valid pair: `[1, 2, 3]`, target `7`
- Empty array: `[]`, target `5`
- Single element: `[5]`, target `5`
- Large numbers: `[1000000, 2000000, 3000000]`, target `5000000`

#### 4. Complexity
- `twoSumArray` (brute-force nested loops)
  - Time: `O(n^2)`
  - Space: `O(1)`

- `twoSumHashTable`
  - Time: `O(n)` average-case
  - Space: `O(n)`

#### 5. Automated Testing
- **GitHub Actions** CI/CD pipeline for automatic test execution
- Workflow file: `.github/workflows/ci.yml`
- Tests run on every push and pull request
- Multiple OS environments (Ubuntu, Windows)

#### 6. Run Locally
- With GCC on Linux/macOS/Windows:
  ```bash
  g++ -std=c++20 -Wall -Wextra src/main.cpp src/twosum.cpp -o twosum_test
  ./twosum_test
  ```

#### 7. Project Documentation
- Test plan: `docs/04_test_plan.md`
- CI/CD guide: `docs/05_ci_cd.md`


