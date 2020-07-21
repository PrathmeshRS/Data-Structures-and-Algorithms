// This program prints the matrix  elements in spiral pattern(clock-wise)
#include<iostream>
#define R 5
#define C 5
using namespace std;

void printSpiral(int mat[R][C]){
    int top = 0, right = C-1, bottom = R-1, left = 0;
    while(top<=bottom && left<=right) {
        for(int i = left; i <= right; i++)
            cout << mat[top][i] << " ";
        top++;
        for(int i = top; i <= bottom; i++)
            cout << mat[i][right] << " ";
        right--;
        if(top <= bottom) {
            for(int i = right; i >= left; i--)
                cout << mat[bottom][i] << " ";
        }
        bottom--;
        if(left <= right){
            for(int i = bottom; i >= top; i--)
                cout << mat[i][left] << " ";
        }
        left++;
    } 
}

int main() {
    int mat[R][C], count = 1;
    cout << "Our Matrix is:\n";
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            mat[i][j] = count++;
            cout << mat[i][j] << " ";
        }        
        cout << "\n";
    }
    cout << "\nOur spiral Printing is:\n";
    printSpiral(mat);

    return 0;
}