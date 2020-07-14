/* This program sorts a small ranged array in linear time by using counting sort */
#include<iostream>
using namespace std;

// This algorithm is of O(n+k) time complexity. So it works good only when k is linear to n.
// cannot be used for general purpose only for numbers
void countSort(int arr[], int n, int k) {
    int count[k] = {0};
    for(int i = 0; i < n; i++)
        count[arr[i]]++;
    int index = 0;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < count[i]; j++)
            arr[index++] = i;
    }
    
}

// The following algorithm ca be used for general purpose i.e integers, objects, etc.
void GpCountSort(int arr[], int n, int k) {
    int count[k] = {0};
    for(int i = 0; i < n; i++) count[arr[i]]++;
    for(int i = 1; i < k; i++) count[i] = count[i-1] + count[i];
    int output[n];
    for(int i = n-1; i >= 0; i--) {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    for(int i = 0; i < n; i++) arr[i] = output[i];
}

int main() {
    int n; cout << "Please enter the length of the array: "; cin >> n;
    int arr[n]; cout << "Please enter those " << n << " elements:\n";
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k; cout << "Please enter the highest element of the array: "; cin >> k;
    GpCountSort(arr, n, k+1);
    cout << "Your array is now:\n";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}