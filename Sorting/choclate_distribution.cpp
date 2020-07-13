/* This program finds the difference between minimum and maximim number of chocolates m number of children gets.
    IP: arr[] = {7, 3, 2, 4, 9, 12, 56} //The packets with number of choclates in it. 
        m=3 //the number of children where each child can only one choclate packet.
    OP: 2 // the packets 3, 2 and 4

    IP: arr[] = {3, 4, 1, 89, 56, 7, 9, 12}  m = 5 
    OP: 6

 */

#include<iostream>
#include<algorithm>
using namespace std;

int minDiff(int arr[], int n,  int m) {
    if(m > n) return -1;
    sort(arr, arr+n);
    int res = arr[m-1] - arr[0];  // maximum possible difference
    for(int i = 1; (i+m-1) < n; i++) 
        res = min(res, (arr[i+m-1] - arr[i]));
    return res;
}

int main() {
    int n; cout << "Please enter the number of packets: "; cin >> n;
    int arr[n]; cout << "Please enter the number of chocolates present in each packet: \n";
    for(int i = 0; i < n; i++) cin >> arr[i];
    int m; cout << "How many children? "; cin >> m;
    cout << "The difference between minimum and maximim chocolates a child gets is: " << minDiff(arr, n, m) << endl;

    return 0;
}

