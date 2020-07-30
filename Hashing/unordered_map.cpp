#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    unordered_map<string,int>um;
    // Ways of inserting values in unordered map
    um["Sachin"] = 20;
    um["Messi"] = 22;
    um.insert({"Friends", 30});
    um.insert({"Score", 10});

    // first and second methods
    cout << "Contents of our map: \n";
    for(auto x: um) cout << x.first << " " << x.second <<endl;
    cout << "Finding friendship day\n" ;
    if(um.find("Friends") != um.end()) cout << "Friendship day falls on: "<< um.find("Friends")->second << " of July 2020\n";

    return 0;
}