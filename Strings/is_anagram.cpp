// Find if given two strings are anagrams
#include<iostream>
#include<algorithm>
using namespace std;

const int CHAR=256;

// A naive solution
bool areAnagram(string &s1, string &s2) {
    if (s1.length() != s2.length()) 
        return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return(s1 == s2);
}

// A better O(n) solution
bool are_anagram(string &s1, string &s2) {
    if(s1.length() != s2.length())
        return false;
    int count[CHAR] = {0};
    for(int i = 0; i < s1.length(); i++){
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for(int i = 0; i < CHAR; i++)
        if(count[i] != 0)
            return false;
    return true;
}

int main() {
    string s1, s2;
    cout << "Please enter two strings to check if they are anagrams: ";
    cin >> s1 >>  s2;
    if(are_anagram(s1, s2) == true)
        cout << "\nGiven strings are anagrams!";
    else cout << "\nGiven strings are not anagrams!";

    return 0;
}