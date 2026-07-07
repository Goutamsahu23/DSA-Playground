# 3Sum Closest

Find the sum of three numbers in an array that is closest to a given target.

## Problem

Given an integer array `nums` and an integer `target`, find three integers in `nums` such that the sum is closest to `target`.

Return that closest sum. You may assume each input has exactly one closest sum.

### Examples

| Input | Target | Closest Sum |
|-------|--------|-------------|
| `[-1, 2, 1, -4]` | `1` | `2` (`-1 + 2 + 1`) |
| `[0, 0, 0]` | `1` | `0` |
| `[1, 1, 1, 0]` | `-100` | `2` |

## Approach (Sort + Two Pointers)

This program sorts the array, fixes one element, and uses two pointers to search for the best remaining pair.

1. Sort `nums`.
2. Initialize `closest` to the sum of the first three elements.
3. Loop with index `i` from `0` to `n - 3`:
   - Set `left = i + 1` and `right = n - 1`.
   - While `left < right`:
     - Compute `sum = nums[i] + nums[left] + nums[right]`.
     - If `sum` is closer to `target` than `closest`, update `closest`.
     - If `sum < target`, move `left` forward.
     - If `sum > target`, move `right` backward.
     - If `sum == target`, return `sum` immediately (cannot get closer).
4. Return `closest`.

### Why it works

Fixing `nums[i]` reduces the problem to finding two numbers whose sum is closest to `target - nums[i]` in a sorted subarray. Two pointers efficiently explore that subarray for each `i`, similar to 3Sum but tracking the minimum difference instead of collecting exact matches.

## Program Structure

```cpp
int threeSumClosest(vector<int>& nums, int target);
```

- Reads the array size, elements, and target from standard input in `main`.
- Sorts the array inside `threeSumClosest`.
- Prints `Closest Sum = <value>`.

## Complexity

| | Time | Space |
|---|------|-------|
| Sort + two pointers (this solution) | O(n²) | O(1) extra |

Sorting takes O(n log n). The nested two-pointer scan is O(n²).

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
Enter number of elements: 4
Enter array elements: -1 2 1 -4
Enter target: 1
Closest Sum = 2
```

Another example:

```
Enter number of elements: 3
Enter array elements: 0 0 0
Enter target: 1
Closest Sum = 0
```

## 3Sum vs 3Sum Closest

| | 3Sum | 3Sum Closest |
|---|------|--------------|
| Goal | Triplets that sum to exactly `0` | Triplet sum closest to `target` |
| Output | All unique triplets | Single integer (closest sum) |
| On exact match | Record triplet and continue | Return immediately |

## Related Problems

- 3Sum
- Two Sum II — Input Array Is Sorted
- 4Sum
