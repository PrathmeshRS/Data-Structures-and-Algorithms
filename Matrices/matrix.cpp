/* Different matrix types in C++ */
#include<iostream>
#include<vector>
using namespace std;

/* // double pointer array matrix
int main() {
    int m = 3, n = 2;
    int **arr;
    arr = new int *[m];
    for(int i = 0; i < m; i++)
        arr[i] = new int[n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            arr[i][j] = i+j;
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
} */

/* // pointer method
int main() {
    int m = 2, n = 3;
    int *arr[m];
    for(int i = 0; i < m; i++)
        arr[i] = new int[n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = i+j;
            cout <<arr[i][j] <<" ";
        }
        cout << "\n";
    }

    return 0;
} */

/* // array of vectors
int main() {
    int m = 3, n = 2;
    vector<int>arr[m];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            arr[i].push_back(i+j);
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
} */

// vector of vectors
int main() {
    int m = 3, n = 2;
    vector<vector<int>>arr;
    for(int i = 0; i < m; i++) {
        vector<int>v;
        for(int j = 0; j < n; j++) {
            v.push_back(i+j);
        }
        arr.push_back(v);
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}