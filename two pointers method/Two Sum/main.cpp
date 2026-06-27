#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void twoSum(const vector<int>& arr, int target, int& index1, int& index2) {
    vector<pair<int, int>> indexed;

    for (int i = 0; i < arr.size(); i++) {
        indexed.push_back({arr[i], i});
    }

    sort(indexed.begin(), indexed.end());

    int left = 0;
    int right = indexed.size() - 1;

    while (left < right) {
        int sum = indexed[left].first + indexed[right].first;

        if (sum == target) {
            index1 = indexed[left].second;
            index2 = indexed[right].second;
            return;
        }

        if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
}

int main() {
    int n, target;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target: ";
    cin >> target;

    int index1, index2;
    twoSum(arr, target, index1, index2);

    cout << "Indices: " << index1 << " " << index2 << "\n";
    cout << "Values: " << arr[index1] << " + " << arr[index2] << " = " << target << "\n";

    return 0;
}
