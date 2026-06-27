# Two Sum

Find two indices in an array such that the values at those indices add up to a given target.

## Problem

Given an integer array and a target value, find the indices of two numbers that add up to the target. Each input is assumed to have at most one valid pair, and the same element cannot be used twice.

### Examples

| Input | Target | Output |
|-------|--------|--------|
| `[2, 7, 11, 15]` | `9` | `Indices: 0 1` |
| `[3, 2, 4]` | `6` | `Indices: 1 2` |
| `[3, 3]` | `6` | `Indices: 0 1` |

## Approach (Hash Map)

This program uses a hash map to solve the problem in a single pass.

1. Walk through the array from left to right.
2. For each element `nums[i]`, compute `need = target - nums[i]`.
3. If `need` is already in the map, we have a pair — print both indices and stop.
4. Otherwise, store `nums[i]` and its index `i` in the map.

### Why it works

When we reach index `i`, the map holds every value we have seen before along with its index. If the complement `target - nums[i]` is in the map, that earlier index and `i` form the answer.

## Program Structure

```cpp
void twoSum(vector<int>& nums, int target);
```

- Reads the array size, elements, and target from standard input in `main`.
- Prints `Indices: <i> <j>` when a pair is found.
- Prints `No pair found` if no valid pair exists.

## Complexity

| | Time | Space |
|---|------|-------|
| Hash map (this solution) | O(n) | O(n) |

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
Enter size of array: 4
Enter array elements: 2 7 11 15
Enter target: 9
Indices: 0 1
```

Another example:

```
Enter size of array: 3
Enter array elements: 1 2 3
Enter target: 10
No pair found
```

## Alternative: Two Pointers

If the array is sorted, you can use two pointers (`left` at the start, `right` at the end) and move them based on whether the current sum is too small or too large. For an unsorted array, you would need to sort first while tracking original indices — that takes O(n log n) time.

The hash map approach used here is simpler and faster for the general unsorted case.
