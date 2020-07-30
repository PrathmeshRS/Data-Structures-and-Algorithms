// This program demontrates unordered set of C++
#include<iostream>
#include<unordered_set>
using namespace std;

int main() {
    int key;

    unordered_set<int>s;
    s.insert(15);
    s.insert(12);
    s.insert(34);
    s.insert(23);
    s.insert(67);
    s.insert(98);
    s.insert(51);
    s.insert(100);

    cout << "Set contents: ";
    for(auto x: s)
        cout << x << " ";
    cout << endl;

    cout << "Set size: " << s.size();
    cout << "Enter the key you wish to search: "; cin >>  key;
    if(s.find(key) != s.end()) cout << "\nKey found at loc: " << *s.find(key);
    else cout << "\nKey not found!";
    cout << "\nEnter the key you wish to remove: "; cin >> key;
    s.erase(key);
    cout << "\nSet size: " << s.size();
    cout << "\nEnter another key you wish to remove: "; cin >> key;
    auto it = s.find(key);
    s.erase(it);
    cout << "\nSet size: " << s.size();
    cout << "\nCleaning set"; s.clear();
    cout << "\nSet size: " << s.size();

    return 0;
}