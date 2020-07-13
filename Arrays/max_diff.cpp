// Program to find the maximum difference arr[j] - arr[i] where j > i

#include<iostream>
#include<climits>
using namespace std;

// A naive solution with time complexity of O(n*n)
int naive_diff(int arr[], int n) {
    int max_diff = INT_MIN;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[j] - arr[i] > max_diff) {
                max_diff = arr[j] - arr[i];
            }
        }
    }
    return max_diff;
}

// A best solution with O(n) time complexity
int best_diff(int arr[], int n) {
    int max_diff = arr[1] - arr[0], min_val = arr[0];
    for(int j = 1; j < n; j++) {
        max_diff = max(max_diff, arr[j]-min_val);
        min_val = min(min_val, arr[j]);
    }
    return max_diff;
}

int main() {
    int arr[1000], n;

    cout << "How many elements? ";
    cin >> n;
    cout << "Please type those " << n << " elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << best_diff(arr, n);

    return 0;
}