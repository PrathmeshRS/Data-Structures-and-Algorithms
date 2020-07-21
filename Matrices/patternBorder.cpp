// This program prints the border(outermost) elemets in a clockwise direction
/* Eg:
        1  2   3   4
        5  6   7   8
    IP: 9  10  11  12
        13 14  15  16
    
    OP: 1 2 3 4 8 12 16 15 14 13 9 5

 */
 #include<iostream>
 #define R 4
 #define C 4
 using namespace std;

void broder(int mat[R][C]) {
    for(int j = 0; j < C; j++)
        cout << mat[0][j] << " ";
    for(int i = 1; i < R; i++)
        cout << mat[i][C-1] << " ";
    for(int j = C-2; j >= 0; j--)
        cout << mat[R-1][j] << " ";
    for(int i = R-2; i > 0; i--)
        cout << mat[i][0] << " ";
}

int main() {
    int mat[R][C], count = 1;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            mat[i][j] = count++;
    broder(mat);

    return 0;
}