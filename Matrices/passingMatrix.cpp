// This program shows how to pass matrices as arguments to functions
#include<iostream>
#include<vector>
using namespace std;

// --------C-style--------------
/* void printIt(int **arr, int m, int n) {
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    int **arr;
    int m = 5, n = 5;
    arr = new int*[m];
    for(int i = 0; i < m; i++){
        arr[i] = new int[n];
        for(int j = 0; j < n; j++)
            arr[i][j] = i*j;
    }
    printIt(arr, m, n);

    return 0;
} */
// ----------------------------------------
/* void printIt(int *arr[], int m, int n) {
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    int m = 5, n = 5;
    int *arr[m];
    for(int i = 0; i < m; i++){
        arr[i] = new int[n];
        for(int j = 0; j < n; j++)
            arr[i][j] = i+j;
    }
    printIt(arr, m, n);

    return 0;
} */

// ------C++ vector based------------------
/* void printIt(vector<int>arr[], int m) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    int m = 5, n = 5;
    vector<int>arr[m];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            arr[i].push_back(max(i, j));
    printIt(arr, m);
    return 0;
} */

// --------- C++ vector of vector ---------
void printIt(vector<vector<int>>&arr) {
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    int m = 5, n = 5;
    vector<vector<int>>arr;
    for(int i = 0; i < m; i++) {
        vector<int>v;
        for(int j = 0; j < n; j++) {
            v.push_back(min(i, j));
        }
        arr.push_back(v);
    }
    printIt(arr);

    return 0;
}