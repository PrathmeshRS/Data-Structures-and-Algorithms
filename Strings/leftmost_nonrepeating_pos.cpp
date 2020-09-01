// Find the index(position) of the leftmost non repeating character in  the given string
#include<iostream>
#include<limits.h>
using namespace std;

// A naive solution -> O(n2)
int nonrep(string &str) {
    for(int i = 0; i < str.length(); i++) {
        bool flag = false;
        for(int j = 0; j < str.length(); j++) {
            if(i != j && str[i] == str[j]) {
                flag == true;
                break;
            }
        }
        if(flag == false)
            return i;
    }
    return -1;
}

// A better solution -> O(2n)
const int CHAR = 256;
int non_rep(string &str) {
    int count[CHAR] = {0};
    for(int i = 0; i < str.length(); i++)
        count[str[i]]++;
    for(int i = 0; i < str.length(); i++)
        if(count[str[i]] == 1)
            return i;
    return -1;
}

// Optimised solution -> O(n)
int nonRep(string &str) {
    int fI[CHAR];
    fill(fI, fI+CHAR, -1);
    for(int i = 0; i < str.length(); i++) {
        if(fI[str[i]] == -1)
            fI[str[i]] = i;
        else
            fI[str[i]] = -2;
    }
    int res = INT_MAX;
    for(int i = 0; i < CHAR; i++)
        if(fI[i] >= 0)
            res = min(res, fI[i]);
    return res==INT_MAX?-1:res;
}

int main() {
    string str; cout << "Please enter a string of your choice: "; cin >> str;
    if(nonRep(str) != -1) 
        cout << "The index of leftmost non repeating character in given string is " << nonRep(str);
    else
        cout << "All the characters in given string are repeated ones";

    return 0;
}