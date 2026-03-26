# Software Requirements Specification (SRS)

## 1. Functional Requirements

### FR1: Two Sum Array Implementation
- **ID**: FR1
- **Description**: Implement the two sum problem using a sorted array with two-pointer approach
- **Input**: Vector of integers and target integer
- **Output**: Vector containing two 0-based indices
- **Constraints**: 
  - Array indices must be 0-based
  - Return indices in ascending order

### FR2: Two Sum Hash Table Implementation
- **ID**: FR2
- **Description**: Implement the two sum problem using hash table (unordered_map)
- **Input**: Vector of integers and target integer
- **Output**: Vector containing two 0-based indices
- **Constraints**:
  - Must use single pass algorithm
  - Return indices in ascending order

### FR3: Main Program
- **ID**: FR3
- **Description**: Create main driver program to test both implementations
- **Features**:
  - Multiple test cases demonstrating both approaches
  - Clear output formatting showing inputs and results
  - Verification of results

### FR4: Edge Case Handling
- **ID**: FR4
- **Description**: Handle edge cases gracefully
- **Cases**:
  - No valid pair found → return empty vector
  - Negative numbers in array
  - Duplicate values
  - Zero values
  - Large numbers
  - Single element arrays

## 2. Non-Functional Requirements

### NFR1: Performance
- **ID**: NFR1
- **Requirement**: Array approach should complete in O(n log n) time
- **Requirement**: Hash table approach should complete in O(n) time

### NFR2: Memory Usage
- **ID**: NFR2
- **Requirement**: Space complexity for both approaches: O(n)
- **Constraint**: No external libraries beyond STL

### NFR3: Code Quality
- **ID**: NFR3
- **Requirement**: Code must compile without warnings using `-Wall -Wextra`
- **Requirement**: Code must follow C++20 standards

### NFR4: Portability
- **ID**: NFR4
- **Requirement**: Code must compile on multiple C++20 compilers (GCC, Clang, MSVC)

### NFR5: Maintainability
- **ID**: NFR5
- **Requirement**: Code must be well-commented and documented
- **Requirement**: Clear variable names and function documentation

## 3. Constraints

- Language: C++20
- No external dependencies beyond STL
- Target platform: Windows, Linux, macOS
- Array indices: 0-based
- Input: Integer array and integer target value
- Output: Vector of two indices or empty vector

## 4. Glossary

- **Two Sum Problem**: Find two distinct elements in an array that sum to a target value
- **Indices**: 0-based positions in the array
- **Two Pointers**: Algorithm technique using left and right pointers moving towards each other
- **Hash Table**: Data structure for fast lookups (implemented via unordered_map)
