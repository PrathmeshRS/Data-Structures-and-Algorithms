// This program implements hashing with linear probing

#include<iostream>
using namespace std;

struct MyHash {
    int cap, size, table[100];
    MyHash(int b) {
        cap = b;
        size = 0;
        cout << "In constructor";
        for(int i = 0; i < cap; i++){
            table[i] = -1;                // -1 is used for denoting empty slots of hash table. We do not consider -1 and -2 to be our input keys
        }
    }

    int hash(int key) {
        return key%cap;
    }

    bool insert(int key) {
        if(size == cap) return false;
        int h = hash(key);
        int i = h;
        while(table[i] != key) {
            if(table[i] == key) return false;
            else {
                table[i] = key;
                size++;
                return true;
            }
            i = (i+1)%cap;
        }
        return false;
    }

    bool search(int key) {
        int h = hash(key);
        int i = h;
        cout << table[i] << endl;
        while(table[i] != -1) {
            if(table[i] == key) return true;
            i = (i+1)%cap;
            if( i == h) break;
        }
        return false;
    }

    bool erase(int key) {
        int h = hash(key);
        int i = h;
        while(table[i] != -1) {
            if(table[i] == key) {
                table[i] = -2;
                size--;
                return true;
            }
            i = (i+1)%cap;
            if(i == h) return false;
        }
        return false;
    }

};

int main() {
    int choice, b, key;
    cout << "Enter bucket size for new hash table: "; cin >> b;
    MyHash obj = MyHash(b);
    do {
        cout << "\nPress\n1 for inserting a key\n";
        cout << "2 for searching a key\n3 for removing a key\n0 to exit >> ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "\nPlease enter the key: "; cin >> key;
                if(obj.insert(key)==true) cout << "\nKey inserted";
                else cout << "\nSorry! Hash table full or key already present";
                break;
            case 2:
                cout << "\nPlease enter the key you wish to search: "; cin >> key;
                if(obj.search(key) == true) cout << "\nKey found";
                else cout << "\nKey not found";
                break;
            case 3:
                cout << "\nPlease enter the key you wish to remove: "; cin >> key;
                if(obj.erase(key)== true) cout << "\nKey removed";
                else cout << "\nkey not found";
                break;
            case 0:
                return 0;
            default:
                cout << "\nEnter a valid choice please.";
                break;                
        }
    }while(true);
}