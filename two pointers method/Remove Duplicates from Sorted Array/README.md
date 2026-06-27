# Remove Duplicates from Sorted Array

Remove duplicate values from a sorted array in-place and return how many unique elements remain.

## Problem

Given a sorted integer array, remove duplicates so each value appears at most once. The unique elements should stay at the front of the array. Return the count of unique elements.

The input array must be **sorted** in non-decreasing order.

### Examples

| Input | Unique count | Array after removal |
|-------|--------------|---------------------|
| `[1, 1, 2]` | `2` | `[1, 2]` |
| `[0, 0, 1, 1, 1, 2, 2, 3, 3, 4]` | `5` | `[0, 1, 2, 3, 4]` |
| `[5]` | `1` | `[5]` |

## Approach (Two Pointers)

This program uses a slow/fast two-pointer technique to overwrite duplicates in a single pass.

1. Keep `i` at the last position of the unique portion (starts at `0`).
2. Scan with `j` from `1` to `n - 1`.
3. When `nums[j]` differs from `nums[i]`, place `nums[j]` at `nums[i + 1]` and move `i` forward.
4. Return `i + 1` as the number of unique elements.

### Why it works

Because the array is sorted, duplicates are always adjacent. The slow pointer marks where the next unique value should go, and the fast pointer finds the next new value to keep.

## Program Structure

```cpp
int removeDuplicates(vector<int>& nums);
```

- Reads the array size and sorted elements from standard input in `main`.
- Prints `Unique count: k` where `k` is the return value.
- Prints the first `k` elements of the modified array.

## Complexity

| | Time | Space |
|---|------|-------|
| Two pointers (this solution) | O(n) | O(1) |

No extra array is needed — duplicates are removed by overwriting in place.

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
Enter size: 10
Enter sorted array: 0 0 1 1 1 2 2 3 3 4
Unique count: 5
Array after removing duplicates: 0 1 2 3 4
```

Another example:

```
Enter size: 3
Enter sorted array: 1 1 2
Unique count: 2
Array after removing duplicates: 1 2
```

## Related Problems

- Remove Duplicates from Sorted Array II (allow at most two copies)
- Merge Sorted Array
- Move Zeroes
