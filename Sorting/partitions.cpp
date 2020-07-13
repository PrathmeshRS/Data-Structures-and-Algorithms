/* This is a program to show different partition algos */
#include<iostream>
using namespace std;

// Naive partition O(3n), Aux: O(n), pivot of choice
void partition(int arr[], int l, int h, int p) {
    int temp[h-l+1], index=0;
    for(int i = l; i <= h; i++) 
        if(arr[i] < arr[p])
            temp[index++] = arr[i];
    for(int i = l; i <= h; i++)
        if(arr[i] >= arr[p])
            temp[index++] = arr[i];
    for(int i = l; i <= h; i++){ 
        arr[i] = temp[i-l];
        cout << arr[i] << " ";
    }
}

// Swap function
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Lomuto partition O(n), Aux: O(1), pivot always at end
int lpartition(int arr[], int l, int h) {
    int pivot = arr[h], i = l-1;
    for(int j = l; j < h; j++){
        if(arr[j] < pivot){
            i++; swap(arr, i, j);
        }
    }
    swap(arr, i+1, h);
    return i+1;
}

// Hoare Partition O(n), Aux: O(1), pivot always at start
int hpartition(int arr[], int l, int h) {
    int pivot = arr[l], i = l-1, j = h+1;
    while(true) {
        do{
            i++;
        }while(arr[i] < pivot);
        do{
            j--;
        }while(arr[j] > pivot);
        if(i >= j) return j;
        swap(arr, i, j);
    }
}

int main() {
    int n; cout << "How many elements in the array?"; cin >> n;
    int arr[n]; cout << "Please enter random " << n << " elements\n";
    for(int i = 0; i < n; i++) cin >> arr[i];

    partition(arr, 0, n-1, 3);

    return 0;
}