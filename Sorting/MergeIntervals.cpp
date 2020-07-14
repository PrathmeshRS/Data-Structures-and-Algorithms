/* This ia program to merge overlapping intervals in a given array of intervals
    
    IP: arr[] = {{1, 3}, {2, 4}, {5, 7}, {6, 8}}
    OP: arr[] = {{1, 4}, {6, 10}}

    IP: arr[] = {{7, 9}, {6, 10}, {4, 5}, {1, 3}, {2, 4}}
    OP: arr[] = {{1, 9}, {6, 10}}

*/

#include<iostream>
#include<algorithm>
using namespace std;

struct Interval
{
    int st, end;
};

int myComp(Interval s1, Interval s2) {
    return (s1.st < s2.st);
}

void mergeIntervals(Interval arr[], int n) {
    sort(arr, arr+n, myComp);
    int res = 0;
    for(int i = 1; i < n; i++) {
        if(arr[res].end >= arr[i].st){
            arr[res].end = max(arr[res].end , arr[i].end);
            arr[res].st = min(arr[res].st, arr[i].st);
        }
        else {
            res++; 
            arr[res] = arr[i];
        }
    }
    cout << "Merged intervals are:\n";
    for(int i = 0; i <= res; i++) {
        cout << "{" << arr[i].st << ", " << arr[i].end << "}\n";
    }
}

int main() {
    int n; cout << "Please enter the number of Intervals: "; cin >> n;
    Interval arr[n]; cout << "Please enter the start and end of each interval seperated by space:\n"; 
    for(int i = 0; i < n; i++) cin >> arr[i].st >> arr[i].end; 

    mergeIntervals(arr, n);

    return 0;
}
