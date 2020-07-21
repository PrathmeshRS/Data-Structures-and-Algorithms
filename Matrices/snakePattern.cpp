// This program prints the contents of matrix in a snake pattern
/* eg:
        1 2 3 4
    IP: 5 6 7 8
        9 10 11 12
        13 14 15 16
    OP: 1 2 3 4 8 7 6 5 9 10 11 12 16 15 14 13

 */

#include<iostream>
#include<vector>
using namespace std;

void printSnake(vector<vector<int>>&arr) {
    for(int i = 0; i < arr.size(); i++){
        if(i%2 == 0){
            for(int j = 0; j < arr[i].size(); j++)
                cout << arr[i][j] << " ";
        }
        else {
            for(int j = arr[i].size()-1; j >= 0; j--)
                cout << arr[i][j] << " ";
        }
    }
}

int main() {
    int m = 4, n = 4, count=1;
    vector<vector<int>>arr;
    for(int i = 0; i < m; i++){
        vector<int>v;
        for(int j = 0; j < n; j++)
            v.push_back(count++);
        arr.push_back(v);
    }
    printSnake(arr);

    return 0;
}