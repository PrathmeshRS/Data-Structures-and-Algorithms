// This program calculates the number of distinct elemets in an array
#include<iostream>
#include<unordered_set>
using namespace std;

// By using hashing technique of set we can find number of distinct elements in O(1)
int main() {
    int n, x;          // size of original array and array element variable
    unordered_set<int>us;              
    cout << "How many elements in  the array: "; cin >> n;
    cout << "\nEnter the array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> x; 
        us.insert(x);
    }
    cout << "\nThe number of distinct elements in given array is: " << us.size();

    return 0;
}