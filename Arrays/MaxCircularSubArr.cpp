/* This is a program to find the max sum of a circular sub array */
#include<iostream>
using namespace std;

// Naive Solution
int maxCircularSum(int arr[], int n) {
    int res = arr[0];
    for(int i = 0; i < n; i++) {
        int curr_max = arr[i], curr_sum = arr[i];
        for(int j = 1; j < n; j++) {
            int index = (i+j) % n;
            curr_sum += arr[index];
            curr_max = max(curr_max, curr_sum);
        }
        res = max(res, curr_max);
    }
    return res;
}

// A brtter solution
int normalMaxSum(int arr[], int n) {
    int res = arr[0], maxEnding = arr[0];
    for(int i = 0; i < n; i++) {
        maxEnding = max(arr[i], maxEnding+arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}

int overallSum(int arr[], int n) {
    int max_normal = normalMaxSum(arr, n);
    if(max_normal < 0) return max_normal;
    int arr_sum = 0;
    for(int i = 0; i < n; i++) {
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }
    int max_circular = arr_sum + normalMaxSum(arr, n);
    return max(max_normal, max_circular);
}

int main() {
    int n; cout << "Please enter the length of array: "; cin >> n;
    int arr[n]; cout << "Please enter " << n << "positive negative integers: \n";
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "The sum of max sum circular sub array is: " << overallSum(arr, n);

    return 0; 
}
