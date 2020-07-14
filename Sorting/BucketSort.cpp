/* This is a program to sort a uniform */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bucketSort(int arr[], int n, int k) {
    int max_val = arr[0];
    for(int  i = 0; i < n; i++)
        max_val = max(max_val, arr[i]);
    max_val++;
    vector<int>bkt[k];
    for(int i = 0; i < n; i++) {
        int bi = (k*arr[i])/max_val;
        bkt[bi].push_back(arr[i]);
    }
    for(int i = 0; i < k; i++) sort(bkt[i].begin(), bkt[i].end());
    int index = 0;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < bkt[i].size(); j++)
            arr[index++] = bkt[i][j];
    }
}

int main() {
    int n; cout << "Please enter the length of the array: "; cin >> n;
    int arr[n]; cout << "Please enter those " << n << " elements:\n";
    for(int i = 0; i < n; i++) cin >> arr[i];
    bucketSort(arr, n);
    cout << "The array is sorted to: \n"; for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}