# Test Plan

## Unit tests
- normal case: [2,7,11,15], target 9 -> indices {0,1}
- duplicate values: [3,3], target 6 -> {0,1}
- negative/numbers: [-1,-2,-3,-4,-5], target -8 -> {2,4}
- zero case: [0,4,3,0], target 0 -> {0,3}
- no solution: [1,2,3], target 7 -> none
- edge cases: [] and [1]

## Evaluation steps
1. Build the project.
2. Run the executable.
3. Verify output for all cases repeats expectations.
