# Two Sum II — Input Array Is Sorted

Find two numbers in a sorted array that add up to a target, using 1-based indices.

## Problem

Given a **sorted** integer array `numbers` (non-decreasing order) and a `target`, find two numbers such that they add up to `target`.

Return their indices as a 1-based pair `[index1, index2]` where `index1 < index2`. Exactly one valid answer is guaranteed.

### Examples

| Input | Target | Output |
|-------|--------|--------|
| `[2, 7, 11, 15]` | `9` | `Indices: 1 2` |
| `[2, 3, 4]` | `6` | `Indices: 1 3` |
| `[-1, 0]` | `-1` | `Indices: 1 2` |

## Approach (Two Pointers)

Because the array is already sorted, no hash map or extra sorting is needed.

1. Place `left` at the start and `right` at the end.
2. Compute `sum = numbers[left] + numbers[right]`.
3. If `sum == target`, return `left + 1` and `right + 1` (1-based indices).
4. If `sum < target`, move `left` forward to increase the sum.
5. If `sum > target`, move `right` backward to decrease the sum.

### Why it works

On a sorted array, moving `left` right increases the sum, and moving `right` left decreases it. That lets you narrow in on the target pair in one linear scan.

## Program Structure

```cpp
void twoSum(vector<int>& numbers, int target, int& index1, int& index2);
```

- Reads the array size, sorted elements, and target from standard input in `main`.
- Prints `Indices: index1 index2` using **1-based** positions.
- Prints the matching values from the array.

## Complexity

| | Time | Space |
|---|------|-------|
| Two pointers (this solution) | O(n) | O(1) |

## Build and Run

```bash
g++ -std=c++17 -O2 -o main main.cpp
./main
```

On Windows with MinGW or similar:

```bash
g++ -std=c++17 -O2 -o main.exe main.cpp
main.exe
```

### Example run

```
Enter array size: 4
Enter sorted array: 2 7 11 15
Enter target: 9
Indices: 1 2
Values: 2 + 7 = 9
```

Another example:

```
Enter array size: 3
Enter sorted array: 2 3 4
Enter target: 6
Indices: 1 3
Values: 2 + 4 = 6
```

## Two Sum vs Two Sum II

| | Two Sum | Two Sum II |
|---|---------|------------|
| Array | Unsorted | Sorted |
| Indices | 0-based | 1-based |
| Typical approach | Hash map | Two pointers |

## Related Problems

- Two Sum
- 3Sum
- Squares of a Sorted Array
