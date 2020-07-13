/* A program to calculate number of inversions in an array 
    Inversion if i < j and arr[i] > arr[j]
*/
#include<iostream>
using namespace std;

// A naive solution
int countInversions(int arr[], int n) {
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) res++;
        }
    }
    return res;
}

// A better solution
int countAndMerge(int arr[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    int left[n1], right[n2];
    for(int i = 0; i < n1; i++) left[i] = arr[l+i];
    for(int i = 0; i < n2; i++) right[i] = arr[m+1+i];
    int res = 0, i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if(left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
            res = res + (n1-i);
        }
        k++;
    }
    while(i < n1) {
        arr[k] = left[i];
        i++; k++;
    }
    while(j < n2) {
        arr[k] = right[j];
        j++; k++;
    }
    return res;
}


int countInv(int arr[], int l, int r) {
    int res = 0;
    if(l < r) {
        int m = l +(r-l)/2;
        res += countInv(arr, l, m);
        res += countInv(arr, m+1, r);
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}


int main() {
    int n; cout << "Please enter the length of array: "; cin >> n;
    int arr[n]; cout << "Please enter those " << n << " elements:\n"; for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "The number of inversions are: " << countInv(arr, 0, n-1);

    return 0;
}
