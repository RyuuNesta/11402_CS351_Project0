## Two Sum

Two Sum is a classic LeetCode algorithm problem where you need to find two numbers in an array that add up to a target value. Given an array of integers and a target sum, return the indices of the two numbers that sum to the target.

### Requirements

#### 1. Programming Language
- **C++ 20** with STL vector

#### 2. Implementations
Two different approaches are required:

##### TwoSumArray
- Two-pointer approach (requires sorted array)
- Time Complexity: O(n log n) due to sorting
- Space Complexity: O(1) or O(n) depending on sorting algorithm

##### TwoSumHashTable
- Hash map/unordered_map approach
- Time Complexity: O(n)
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

#### 4. Automated Testing
- **GitHub Actions** CI/CD pipeline for automatic test execution
- Tests run on every push and pull request
- Multiple OS environments (Ubuntu, Windows)

#### 5. Docker Support
- Dockerfile for containerized build and test environment
- Docker Compose for local development
- Container should include C++ 20 compiler (g++ or clang)
- Automated Docker image building in CI/CD pipeline


