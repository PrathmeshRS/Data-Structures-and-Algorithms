// This program rotates the matrix by 90^ anticlockwise
#include<iostream>
#define N 4
using namespace std;

void rotate90(int mat[N][N]) {
    int temp[N][N];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            temp[N-j-1][i] = mat[i][j];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            mat[i][j] = temp[i][j];
}

void printIt(int mat[N][N]) {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cout << mat[i][j];
    cout << "\n";
}

int main() {
    int mat[N][N], count = 1;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            mat[i][j] = count++;
    cout << 'Original Matrix:\n';
    printIt(mat);
    rotate90(mat);
    cout << "Matrix after 90deg anti-clockwise rotation";
    printIt(mat);

    return 0;
}