# Two Sum (CS351 Project)

This repository implements the Two Sum problem in C++ with two approaches:
- `twoSumArray` (sorted array with two pointers)
- `twoSumHashTable` (hash table / unordered_map)

## Features
- C++20 implementation (STL vectors, unordered_map)
- 0-based indices in solution
- Covers duplicate values, negative numbers, zero values, and edge cases
- Sample runner in `src/main.cpp`

## Build
Use a C++20-compliant compiler.

Example:

```
g++ -std=c++20 -Wall -Wextra -o twosum src/main.cpp src/twosum.cpp
./twosum
```

## Project Docs
- `docs/00_intended_use.md` - Intent of the system
- `docs/01_plan.md` - Project plan
- `docs/02_SRS.md` - Software requirements specification
- `docs/03_SDS.md` - Software design specification
- `docs/04_test_plan.md` - Test plan
- `docs/05_acceptance_tests.md` - Acceptance criteria and tests
- `docs/06_traceability.md` - Requirement traceability matrix
- `docs/07_deploy.md` - Deployment instructions
- `docs/08_known_issues.md` - Known issues

## Testing
Manual smoke test included in `src/main.cpp`.
Refer to `docs/04_test_plan.md` for detailed test-cases and expected results.
