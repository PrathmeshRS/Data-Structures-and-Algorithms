// Print the frequencies of characters (in sorted order) in a string of lower-case alphabets

#include<iostream>
#include<string>
using namespace std;

void countFrequency(string str){
    int freq[26] = {0};
    for(int i = 0; i < str.length(); i++)
        freq[str[i]-'a']++;
    for(int i = 0; i < 26; i++)
        if(freq[i]>0)
            cout << (char)('a'+ i) << ": "<< freq[i] << "\n";
}

int main(){
    string str; cout << "Please provide a string of lower-case alphabets: "; cin >> str;
    cout << "The frequencies of characters in given string are:\n";
    countFrequency(str);

    return 0;
}