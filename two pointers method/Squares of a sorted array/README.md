# Squares of a Sorted Array

Return a new array containing the squares of each element, sorted in non-decreasing order.

## Problem

Given a sorted integer array `nums` (sorted in non-decreasing order), square each element and return the results in sorted order.

The input may contain negative numbers. Squaring them can produce values larger than squaring the positive numbers at the end of the array, so you cannot simply square left to right.

### Examples

| Input | Output |
|-------|--------|
| `[-4, -1, 0, 3, 10]` | `[0, 1, 9, 16, 100]` |
| `[-7, -3, 2, 3, 11]` | `[4, 9, 9, 49, 121]` |
| `[1, 2, 3]` | `[1, 4, 9]` |

## Approach (Two Pointers)

This program uses two pointers from opposite ends of the array and fills the answer from right to left.

1. Set `left` at the start and `right` at the end of the array.
2. Set `pos` to the last index of the result array.
3. Compare `nums[left]²` and `nums[right]²`:
   - Place the larger square at `ans[pos]`.
   - Move the pointer that produced the larger value inward.
4. Decrease `pos` and repeat until `left > right`.

### Why it works

In a sorted array, the largest squared values always come from one of the two ends — negative numbers on the left can square to large positives, while large positives on the right also produce large squares. By always picking the larger of the two end squares and filling the result from the back, the output stays sorted without an extra sort step.

## Program Structure

```cpp
vector<int> sortedSquares(vector<int>& nums);
```

- Reads the array size and sorted elements from standard input in `main`.
- Returns a new vector with the squared values in sorted order.
- Prints `Sorted squares:` followed by the result.

## Complexity

| | Time | Space |
|---|------|-------|
| Two pointers (this solution) | O(n) | O(n) |

An alternative is to square every element and sort — that takes O(n log n) time. The two-pointer approach avoids the extra sort.

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
Enter size of array: 5
Enter sorted array elements: -4 -1 0 3 10
Sorted squares: 0 1 9 16 100
```

Another example:

```
Enter size of array: 3
Enter sorted array elements: 1 2 3
Sorted squares: 1 4 9
```

## Related Problems

- Merge Sorted Array
- Sort Colors
- Two Sum II — Input Array Is Sorted
