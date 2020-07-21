// This program prints the transpose of a matrix

#include<bits/stdc++.h>
#define N 4 
using namespace std;

void Transpose(int mat[N][N]) {
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

void printIt(int mat[N][N]) {
    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < N; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int mat[N][N],count=1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            mat[i][j] = count++;
        }
        cout << "\n";
    }
    cout << "Original Matrix:\n";
    printIt(mat);
    Transpose(mat);
    cout << "\nMatrix after transpose:\n";
    printIt(mat);

    return 0;
}
