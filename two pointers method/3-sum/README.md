# 3Sum

Find all unique triplets in an array that add up to zero.

## Problem

Given an integer array `nums`, return all unique triplets `[nums[i], nums[j], nums[k]]` such that:

- `i != j`, `i != k`, and `j != k`
- `nums[i] + nums[j] + nums[k] == 0`

The solution set must not contain duplicate triplets.

### Examples

| Input | Output |
|-------|--------|
| `[-1, 0, 1, 2, -1, -4]` | `[-1, -1, 2]`, `[-1, 0, 1]` |
| `[0, 1, 1]` | _(no triplets)_ |
| `[0, 0, 0]` | `[0, 0, 0]` |

## Approach (Sort + Two Pointers)

This solution sorts the array first, then fixes one number and uses two pointers to find the other two.

1. Sort `nums` in non-decreasing order.
2. Loop with index `i` from `0` to `n - 3`:
   - Skip duplicate values of `nums[i]`.
   - Set `j = i + 1` and `k = n - 1`.
   - While `j < k`, compare `nums[j] + nums[k]` with `-nums[i]`:
     - If the sum is too small, move `j` forward.
     - If the sum is too large, move `k` backward.
     - If the sum equals `-nums[i]`, record the triplet `{nums[i], nums[j], nums[k]}`, then move both pointers while skipping duplicates.
3. Return all collected triplets.

### Why it works

After sorting, fixing `nums[i]` turns the rest of the problem into **Two Sum** on a sorted subarray. Two pointers can find matching pairs in linear time for each fixed `i`, giving an overall O(n²) solution. Sorting also makes duplicate skipping straightforward.

## Program Structure

```cpp
vector<vector<int>> threeSum(vector<int>& nums);
```

Implemented inside a `Solution` class in `main.cpp`. The function:

- Sorts the input array in place.
- Returns a vector of triplets (each triplet is a `vector<int>` of size 3).
- Avoids duplicate triplets by skipping repeated values at `i`, `j`, and `k`.

## Complexity

| | Time | Space |
|---|------|-------|
| Sort + two pointers (this solution) | O(n²) | O(1) extra |

Sorting takes O(n log n), and the two-pointer scan is O(n²). Space excluding the output is O(1); sorting may use additional space depending on the implementation.

## Walkthrough

For `nums = [-1, 0, 1, 2, -1, -4]`:

1. After sorting: `[-4, -1, -1, 0, 1, 2]`
2. Fix `i = 0` (`-4`): no valid pair for sum `4`
3. Fix `i = 1` (`-1`): find `[-1, 0, 1]` with `j = 3`, `k = 4`
4. Fix `i = 2` (`-1`): skip — same value as previous `i`
5. Fix `i = 3` (`0`): find `[-1, -1, 2]` with `j = 1`, `k = 5`

Result: `[[-1, -1, 2], [-1, 0, 1]]`


