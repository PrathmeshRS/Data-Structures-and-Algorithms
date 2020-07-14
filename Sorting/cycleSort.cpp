/* This program sorts an array in minimum swaps.*/
#include<iostream>
#include<algorithm>
using namespace std;

void cycleSortDistinct(int arr[], int n) {
    for(int cs = 0; cs < n-1; cs++) {
        int item = arr[cs];
        int pos = cs;
        for(int i = cs+1; i < n; i++)
            if(arr[i] < item) pos++;
        swap(item, arr[pos]);
        while(pos != cs) {
            pos = cs;
            for(int i = cs+1; i < n; i++)
                if(arr[i] < item) pos++;
            swap(item, arr[pos]);
        }
    }
}

int main() {
    int n; cout << "Please enter the length of the array: "; cin >> n;
    int arr[n]; cout << "Please enter those " << n << " elements:\n";
    for(int i = 0; i < n; i++) cin >> arr[i];
    cycleSortDistinct(arr,n);
    cout << "The array is sorted to: \n"; for(int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}
