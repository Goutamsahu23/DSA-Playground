#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int closest = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            // Update closest sum
            if (abs(target - sum) < abs(target - closest)) {
                closest = sum;
            }

            // Move pointers
            if (sum < target) {
                left++;
            }
            else if (sum > target) {
                right--;
            }
            else {
                return sum;   // Exact target found
            }
        }
    }

    return closest;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    int ans = threeSumClosest(nums, target);

    cout << "Closest Sum = " << ans << endl;

    return 0;
}