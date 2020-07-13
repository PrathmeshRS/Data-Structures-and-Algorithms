/* Program to calculate maximum consecutive 1's in a Binary array */
#include<iostream>
using namespace std;

int maxConsecutiveOnes(bool arr[], int n) {
    int res = 0, curr=0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) curr = 0;
        else {
            curr++;
            res = max(res, curr);
        }
    }
    return res;
}

int main() {
    int n; cin >> n;
    bool arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "The maximum consecutive ones in given boolean array are: " << maxConsecutiveOnes(arr, n);

    return 0;
}