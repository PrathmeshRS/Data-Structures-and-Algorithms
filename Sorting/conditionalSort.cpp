/* This is a program for sorting/segregating an array on some given conditions
    
    IP: arr[] = {-1, 4, -3, 7, 8, 1, -4}
    Condition: segragate positive and negative numbers
    OP: arr = {-1, -4, -3, 7, 8, 1, 4}

    IP: arr[] = {3, 2, 21, 53, 6, 88, 9}
    Condition: segragate even and odd numbers
    OP: arr[] = {88, 2, 6, 53, 21, 3, 9}

    IP: arr[] = {0, 1, 1, 0, 0, 0, 1, 0, 1}
    Condition: sort the binary array
    OP: arr[] = {0, 0, 0, 0, 0, 1, 1, 1, 1}

    Modify code according to conditions. Here I've used even-odd condition.
 */

#include<iostream>
using namespace std;

// swap function
void swapIt(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// Here we use modified version of Hoare partition
void sortIt(int arr[], int n) {
    int i = -1, j = n;
    while(true) {
        do{
            i++;
        }while(arr[i]%2 == 0);  // while condition based on even-odd condition of segregating array
        do{
            j--;
        }while(arr[j]%2 != 0);
        if(i >= j) return;
        swapIt(arr, i, j);
    }
}

int main() {
    int n; cout << "Please enter the length of array: "; cin >> n;
    int arr[n]; cout << "Please enter the " << n << " integers:\n";
    for(int i = 0; i < n; i++) cin >> arr[i];
    sortIt(arr, n);
    cout << "Your array is now: "; for(int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}