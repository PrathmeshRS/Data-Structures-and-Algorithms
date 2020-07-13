/* This is a program to sort three type element array also known as Dutch National Flag Algorithm 

    IP: arr[] = {0, 1, 2, 1, 1, 0, 2, 0}
    Condition: Segregate all the 0's, 1's and 2's
    OP: arr[] = {0, 0, 0, 1, 1, 1, 2, 2}

    IP: arr[] = {2, 2, 10, 1, 1, 30, 20, 30}
    Condition: Sort around pivot 2
    OP: arr[] = {1, 1, 2, 2, 10, 30, 20, 30}

    IP: arr[] = {10, 5, 6, 3, 20, 9, 40}
    Condition: Sort around range {5, 10}
    OP: arr[] = {3, 5, 10, 6, 9, 20, 40}

*/
#include<iostream>
#include<algorithm>
using namespace std;

// This algorithms is similar to hoaer's partition. Change the case's according conditions.
/* 
    Parameters:
        arr -> original array with 0, 1 and 2 as elements
        n -> length of array
    Return:
        no return
    Result:
        array is sorted
 */
void SortIt(int arr[], int n) {
    int l = 0, m = 0, h = n-1;
    while(m <= h) {
        switch(arr[m]) {
            case 0: 
                swap(arr[l++], arr[m++]);
                break;
            case 1:
                m++;
                break;
            case 2:
                swap(arr[m], arr[h--]);
                break;
        }
    }
}

// Algorithm for sorting around pivot
/* 
    Parameters: 
        arr -> original array where pivot can be a repeated value
        n -> length of array
        pivot -> array element around which to sort
    Returns:
        no return
    Result:
        array is sorted around the given pivot
 */
void pivotSortIt(int arr[], int n, int pivot) {
    int l = 0, m = 0, h = n-1;
    while(m <= h) {
        if(arr[m] < pivot) swap(arr[l++], arr[m++]);
        else if(arr[m] == pivot) m++;
        else swap(arr[m], arr[h--]);
    }
}

// Algorithm for sorting around a range
/* 
    Parameters: 
        arr -> original array with a wide range
        n -> length of array
        l -> lower range for sorting
        r -> higher range for sorting
    Returns:
        no return
    Result:
        array is sorted with elements lower than range elemets, in-range elements and higher than range elements.
 */
void rangedSortIt(int arr[], int n, int l, int r) {
    int i = 0, m = 0, j = n-1;
    while(m <= j) {
        if(arr[m] < l) {
            swap(arr[i++], arr[m++]);
        }
        else if(arr[m] >= l && arr[m] <= r) {
            m++;
        }
        else {
            swap(arr[m], arr[j--]);
        }
    }
}

int main() {

    int n; cout << "Please enter the length of array: "; cin >> n;
    int arr[n]; cout << "Please enter those " << n << " elements: \n";
    for(int i = 0; i < n; i++) cin >> arr[i];
    int l; cout << "Please enter the lower range number "; cin >> l;
    int r; cout << "Please enter the higher range number "; cin >> r;

    rangedSortIt(arr, n, l, r);
    cout << "Your array is now: "; for(int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}
