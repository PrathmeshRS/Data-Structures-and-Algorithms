/* This is a program to find the intersection of two sorted arrays */
#include<iostream>
using namespace std;

// Naive Solution
void ints(int a[], int b[], int m, int n) {
    for(int i = 0; i < m; i++) {
        if((i > 0 ) && (a[i] = a[i-1])) continue;
        for(int j = 0; j < n; j++) {
            if(a[i] == b[j]) cout << a[i] << endl;
        }
    }
}

// Better solution
void Intersection(int a[], int b[], int m, int n) {
    int i = 0, j = 0;
    while(i < m && j < n) {
        if(i > 0 && a[i-1] == a[i]) {
            i++; continue;
        }
        if(a[i] < b[j]) i++;
        else if(a[i] > b[j]) j++;
        else{
            cout << a[i] << " ";
            i++; j++;
        }
    }
}

int main() {
    int m; cout << "Please enter the length of the first array: "; cin >> m;
    int a[m]; cout << "Please enter those " << m << " elemets.\n"; for(int i = 0; i < m; i++) cin >> a[i];
    int n; cout << "\nPlease enter the length of the second array: "; cin >> n;
    int b[n]; cout << "Please enter those " << n << " elemets.\n"; for(int i = 0; i < n; i++) cin >> b[i];
    cout << "The common elemets are: ";
    Intersection(a, b, m, n);
    return 0;
}