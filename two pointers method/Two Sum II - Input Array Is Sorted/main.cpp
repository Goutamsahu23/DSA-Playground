#include <iostream>
#include <vector>

using namespace std;

void twoSum(vector<int>& numbers, int target, int& index1, int& index2) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == target) {
            index1 = left + 1;
            index2 = right + 1;
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

    vector<int> numbers(n);
    cout << "Enter sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    cout << "Enter target: ";
    cin >> target;

    int index1, index2;
    twoSum(numbers, target, index1, index2);

    cout << "Indices: " << index1 << " " << index2 << "\n";
    cout << "Values: " << numbers[index1 - 1] << " + " << numbers[index2 - 1]
         << " = " << target << "\n";

    return 0;
}
