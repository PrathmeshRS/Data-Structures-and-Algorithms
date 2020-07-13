/* // A program for calculating the amount od water trapped in array
IP : arr = {2, 0, 2}
OP : 2

IP : arr = {3, 0, 1, 2, 5}
OP : 6

IP : arr = {3, 2, 1}
OP : 0 */

#include<iostream>
using namespace std;

int NaiveWater(int arr[], int n) {
    int res = 0;
    for(int i = 1; i < n-1; i++) {
        int lmax = arr[i];
        for(int j = 0; j < i; j++) {
            lmax = max(lmax, arr[j]);
        }
        int rmax = arr[i];
        for(int j = i+1; j < n; j++) {
            rmax = max(rmax, arr[j]);
        }
        res = res+ min(lmax, rmax) - arr[i];
    }
    return res;
}

int getWater(int arr[], int n) {
    int res = 0; 
    int lmax[n], rmax[n];
    lmax[0] = arr[0];
    for(int i = 1; i < n; i++) {
        lmax[i] = max(arr[i], arr[i-1]);
    }
    rmax[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--) {
        rmax[i] = max(arr[i], rmax[i+1]);
    }
    for(int i = 1; i < n-1; i++) {
        res = res + (min(lmax[i], rmax[i])- arr[i]);
    }
    return res;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "Rainwater trapping capacity is:" << getWater(arr, n);

    return 0;
}