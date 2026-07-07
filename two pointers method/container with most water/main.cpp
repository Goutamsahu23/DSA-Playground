#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();

    int left = 0;
    int right = n - 1;
    int ans = 0;

    while (left < right) {
        int width = right - left;
        int h = min(height[left], height[right]);
        int area = width * h;

        ans = max(ans, area);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return ans;
}

int main() {
    int n;

    cout << "Enter number of heights: ";
    cin >> n;

    vector<int> height(n);

    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int result = maxArea(height);

    cout << "Maximum Water Area = " << result << endl;

    return 0;
}