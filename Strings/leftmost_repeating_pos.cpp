// Find the  leftmost position of repeating character in given string
#include<iostream>
#include<limits.h>
using namespace std;

// A naive soln -> O(n2)
int leftmost(string &s1){
    for(int i = 0; i < s1.length(); i++){
        for(int j = i+1; j<s1.length(); j++)
            if(s1[i] == s1[j])
                return i;
    }
    return -1;
}

// An improved solution -> O(2n)
const int CHAR=256;
int left_most(string &str){
    int count[CHAR] = {0};
    for(int i = 0; i < str.length(); i++)
        count[str[i]]++;
    for(int i = 0; i < str.length(); i++)
        if(count[str[i]]>1)
            return i;
    return -1;   
}

// A better solution -> O(n + CHAR)
int left_Most(string &st) {
    int fIndex[CHAR];
    fill(fIndex, fIndex+CHAR, -1);
    int res = INT_MAX;
    for(int i = 0; i < st.length(); i++){
        int fi = fIndex[st[i]];
        if(fi == -1)
            fIndex[st[i]] = i;
        else
            res = min(res, fi);
    }
    return (res == INT_MAX?-1:res);
}

// An optimized version of above(left_Most)
int leftMost(string &str) {
    bool visited[CHAR];
    fill(visited, visited+CHAR, false);
    int res = -1;
    for(int i = str.length()-1; i >= 0; i--) {
        if(visited[str[i]])
            res = i;
        else
            visited[str[i]] = true;
    }
    return res;
}

int main() {
    string str;
    cout << "Please enter a string with repeating characters: "; cin >> str;
    cout << "\nThe leftmost repeating character has position " << (/*leftmost(str) , left_most(str) , left_Most(str) ,*/ leftMost(str));


    return 0;
}
