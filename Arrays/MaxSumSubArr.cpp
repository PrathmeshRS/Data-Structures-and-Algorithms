#include<iostream>
using namespace std;

// Kaden's Algorithm
int maxSum(int arr[], int n) {
    int res = 0;
    int maxEnding = arr[0];
    for(int i = 0; i < n; i++) {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}

int main() {
    int n; cout << "Please enter the length of your array: " ; cin >> n;
    int arr[n]; cout << "Please enter " << n << " positive and negative numbers:\n";
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "The maximum sum subarray has sum: " << maxSum(arr, n);

    return 0;
}