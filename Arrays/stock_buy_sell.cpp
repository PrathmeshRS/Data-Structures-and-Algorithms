// A program to get the total amount through stok buy and sell

#include<iostream>
using namespace std;

int stock(int arr[], int n) {
    int profit = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] > arr[i-1]) {
            profit += (arr[i] -arr[i-1]);
        }
    }
    return profit;
}

int main() {
    int arr[1000], n;
    cout << "How many stock points: ";
    cin >> n;
    cout << "Please enter those " << n << " stock points ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "The profit is " << stock(arr, n);

    return 0; 
}