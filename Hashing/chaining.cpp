// This program shows the implementation of hashing with chaining linked list.
#include<iostream>
#include<list>
using namespace std;

struct MyHash{
    int BUCKET;
    list<int>*table;

    MyHash(){
        BUCKET = 10; table = new list<int>[BUCKET];
    }

    MyHash(int b){
        BUCKET = b; table = new list<int>[BUCKET];
    }

    int hash(int key) {
        return key%BUCKET;
    }

    bool search(int key){
        int i = hash(key);
        for(auto x: table[i])
            if(x == key) return true;
        return false;
    }

    void insert(int key) {
        int i = hash(key);
        table[i].push_back(key);
    }

    void remove(int key) {
        int i = hash(key);
        table[i].remove(key);
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
                obj.insert(key);
                break;
            case 2:
                cout << "\nPlease enter the key you wish to search: "; cin >> key;
                if(obj.search(key) == true) cout << "\nKey found";
                else cout << "\nKey not found";
                break;
            case 3:
                cout << "\nPlease enter the key you wish to remove: "; cin >> key;
                obj.remove(key);
                break;
            case 0:
                return 0;
            default:
                cout << "\nEnter a valid choice please.";
                break;                
        }
    }while(true);
}