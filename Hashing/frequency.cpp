// This program calculates the frequency of elements in an array
#include<iostream>
#include<unordered_map>
using namespace std;

// A naive solution. Time complexity is O(n2)
void printfreq(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        bool flag = false;
        
        for(int j = i-1; j >= 0; j--) {
            if(arr[i] = arr[j]) {
                flag = true;
                break;
            }
        }

        if(flag == true) continue;
        int freq = 1;

        for(int j = i+1; j < n; j++){ 
            if(arr[j] == arr[i]) freq++;
        }
        cout << arr[i] << ": " << freq << endl;
    }
}

// A better solution with O(n) time complexity
void PrintFreq(int arr[], int n) {
    unordered_map<int, int>um;
    for(int i = 0 ; i < n; i++)
        um[arr[i]]++;
    for(auto x: um)
        cout << x.first << ": " << x.second << endl;
}

int main() {
    int n; cout << "How many elements in the array: "; cin >> n;
    int x, arr[n];
    cout << "Enter those elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    PrintFreq(arr, n);

    return 0;
}