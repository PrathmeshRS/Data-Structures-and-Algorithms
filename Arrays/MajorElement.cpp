/* This is a program to find the major element(element that is present more than n/2 times in a n sized array) */
#include<iostream>
using namespace std;

int findMajor(int arr[], int n) {
    int res = 0, count = 1;
    for(int i = 1; i < n; i++) {
        if(arr[res] == arr[i]) count++;
        else count--;
        if(count == 0) {
            count = 1; res = i; 
        }
    }
    count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[res] == arr[i]) count++;
    }
    if(count <= n/2) res = -1;
    return arr[res];
}

int main() {
    int n; cout << "Please enter the length of the array: "; cin >> n;
    int arr[n]; cout << "Enter those elements with a major element:\n";
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "The major element is " << findMajor(arr, n);

    return 0; 
}