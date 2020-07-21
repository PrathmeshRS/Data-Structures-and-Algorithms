// This program searches for element in a row-wise and column-wise ascending order sorted matrix

#include<iostream>
#define R 5
#define C 5
using namespace std;

void search(int mat[R][C], int x) {
    int i = 0, j = C-1;
    while(i<R && j>=0) {
        if(mat[i][j] == x){
            cout << "\nElement found at position: " << i << ", " << j ;
            return;
        }
        else if(mat[i][j] > x) {
            j--;
        }
        else{
            i++;
        }
    }
    cout << "\nSorry! element not found."; 
}

int main() {
    int mat[R][C], count = 1, x;
    cout << "Our matrix is:\n";
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++) {
            mat[i][j] = count;
            count += 2;
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "Enter element to be searched: "; cin >> x;
    search(mat, x);

    return 0;
}