/* This is a program to find the maximum length of even-odd subarray */
#include<iostream>
using namespace std;

// Caden's Algorithm
int maxLenEO(int arr[], int n) {
    int res = 1, curr = 1;
    for(int i = 1; i < n; i++) {
        if((arr[i-1]%2 == 0 && arr[i]%2 != 0) || (arr[i-1]%2 != 0 && arr[i]%2 == 0)){
            curr++;
            res = max(res, curr);
        }
        else curr = 1;
    }
    return res; 
}

int main() {
    int n; cout << "Please enter the length of your array:"; cin >> n;
    int arr[n]; cout << "Please enter the " << n << " even odd numbers: \n"; for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "The maximum length even odd subarray is of " << maxLenEO(arr, n) << " length.";

    return 0;
}