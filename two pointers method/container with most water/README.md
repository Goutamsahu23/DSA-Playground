# Container With Most Water

Find the maximum amount of water a container can hold using vertical lines as walls.

## Problem

Given `n` non-negative integers representing the heights of vertical lines at positions `0` to `n - 1`, find two lines that together with the x-axis form a container that holds the most water.

Return the maximum area of water the container can store.

Area formula: `min(height[i], height[j]) × (j - i)`

### Examples

| Heights | Maximum Area |
|---------|--------------|
| `[1, 8, 6, 2, 5, 4, 8, 3, 7]` | `49` |
| `[1, 1]` | `1` |
| `[4, 3, 2, 1, 4]` | `16` |

## Approach (Two Pointers)

This program uses two pointers starting at opposite ends of the array.

1. Set `left = 0` and `right = n - 1`.
2. While `left < right`:
   - Compute `width = right - left`.
   - Compute `height = min(height[left], height[right])`.
   - Update the answer with `width × height`.
   - Move the pointer at the **shorter** line inward.
3. Return the maximum area found.

### Why it works

The area is limited by the shorter of the two lines. Keeping the taller line and moving the shorter pointer inward is the only way to possibly find a larger area — width decreases every step, so height must increase. Moving the taller pointer can only shrink or keep the same min height while reducing width, so it cannot improve the result.

## Program Structure

```cpp
int maxArea(vector<int>& height);
```

- Reads the number of heights and the height values from standard input in `main`.
- Prints `Maximum Water Area = <value>`.

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
Enter number of heights: 9
Enter heights: 1 8 6 2 5 4 8 3 7
Maximum Water Area = 49
```

Another example:

```
Enter number of heights: 2
Enter heights: 1 1
Maximum Water Area = 1
```

## Related Problems

- Trapping Rain Water
- Two Sum II — Input Array Is Sorted
- 3Sum
