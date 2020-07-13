// Program to find leader elements from a array
// an element is a leader if there is no element which is greater or equal to it's right 
/* 
IP : arr[] = {7, 10, 4, 3, 6, 5, 2}
OP : 10, 6, 5, 2

IP : arr[] = {10, 20, 30}
OP : 30

IP : arr[] = {30, 20, 10}
OP : 30, 20, 10 */

#include<iostream>
using namespace std;

/* Efficient Solution
The last element is always a leader
time Complexity: O(n) (for naive soln it's O(n*n)) */
void leaders(int arr[], int n) {
    int curr_leader = arr[n-1];
    cout << curr_leader << " ";
    for(int i = n-2; i >= 0; i--) {
        if(curr_leader < arr[i]) {
            curr_leader = arr[i];
            cout << curr_leader << " ";
        }
    }
}

int main() {
    int n, arr[1000];

    cout << "How many elements in array?\n";
    cin >> n;
    cout << "Give me the " << n << " elements seperated by space";
    for(int i = 0; i < n; i++) cin >> arr[i];
    leaders(arr, n);

    return 0;
}