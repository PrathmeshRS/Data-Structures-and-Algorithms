// A program to find the union of two sorted arrays
#include<iostream>
using namespace std;

void findUnion(int a[], int b[], int m, int n) {
    int i = 0, j = 0;
    while(i < m && j < n) {
        if(i > 0 && a[i] == a[i-1]){i++; continue;}
        if(j > 0 && b[j] == b[j-1]){j++; continue;}
        if(a[i] < b[j]) { cout << a[i] << " "; i++;}
        else if(a[i] > b[j]) { cout << b[j] << " "; j++;}
        else {cout << a[i] << " "; i++; j++;}
    }
    while(i < m){ 
        if(i == 0 || a[i]!=a[i-1]) {
            cout << a[i] << " ";
        }
        i++; 
    }
    while(j < n){
        if(j == 0 || b[j]!=b[j-1]) {
            cout << b[j] << " ";
        }
        j++; 
    }
}

int main() {
    int m; cout << "Please enter the length of the first array: "; cin >> m;
    int a[m]; cout << "Please enter those " << m << " elemets.\n"; for(int i = 0; i < m; i++) cin >> a[i];
    int n; cout << "\nPlease enter the length of the second array: "; cin >> n;
    int b[n]; cout << "Please enter those " << n << " elemets.\n"; for(int i = 0; i < n; i++) cin >> b[i];
    cout << "The union of both arrays is: ";
    findUnion(a, b, m, n);
    return 0;
}