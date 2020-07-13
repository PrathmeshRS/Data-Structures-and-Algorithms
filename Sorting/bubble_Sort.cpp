#include<iostream>
using namespace std;

void bubble(int arr[], int n) {
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n, arr[1000];

    cout << "How many numbers do you have? ";
    cin >> n;
    cout << "Gimme those numbers now ->> ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    bubble(arr, n);
    cout << "Look, I sorted them: \n"; 
    for(int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}