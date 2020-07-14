/* This program sorts a given array using radix_sort concept */

#include<iostream>
using namespace std;

void countingSort(int arr[], int n, int exp) {
    int count[10] = {0}, output[n];
    for(int i = 0; i < n; i++) count[(arr[i]/exp)%10]++;
    for(int i = 1; i < 10; i++) count[i] += count[i-1];
    for(int i = n-1; i >= 0; i--) {
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int mx = arr[0];
    for(int i = 1; i < n; i++) if(arr[i] > mx) mx = arr[i];
    for(int exp = 1; mx/exp > 0; exp *= 10) countingSort(arr, n, exp);
}

int main() {
    int n; cout << "Please enter the length of the array: "; cin >> n;
    int arr[n]; cout << "Please enter those " << n << " elements:\n";
    for(int i = 0; i < n; i++) cin >> arr[i];
    radixSort(arr, n);
    cout << "Your array is now:\n";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}