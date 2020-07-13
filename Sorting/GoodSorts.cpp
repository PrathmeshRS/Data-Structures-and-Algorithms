/* A selection sort algorithm implementation */
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i-1;
            while(j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key; 
    }
}

// Selection Sort
void swapit(int arr[], int i, int min_indx) {
    int temp = arr[i];
    arr[i] = arr[min_indx];
    arr[min_indx] = temp;
}
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int min_indx = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min_indx]) min_indx = j;
            swapit(arr, i, min_indx);
        }
    }
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r - m;
    int left[n1], right[n2];
    for(int i = 0; i < n1; i++) left[i] = arr[l+i];
    for(int i = 0; i < n2; i++) right[i] = arr[m+1+i];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(left[i] < right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while(i < n1) arr[k++] = left[i++];
    while(j < n2) arr[k++] = right[j++];

}
void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}


int main() {
    int n; cout << "Please enter the length of the array: "; cin >> n;
    int arr[n]; cout << "Please enter those " << n << " elements:\n";
    for(int i = 0; i < n; i++) cin >> arr[i];
    mergeSort(arr,0, n-1);
    cout << "The array is sorted to: \n"; for(int i = 0; i < n; i++) cout << arr[i] << " ";
    shuffle(arr, arr+n, default_random_engine(0));

    return 0;
}