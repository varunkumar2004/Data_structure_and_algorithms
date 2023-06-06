#include <iostream>
#include <map>
using namespace std;

// Time Complexity -> O(logn)
int main() {
    map<int, string> m;
    m[1] = "babbar";
    m[2] = "love";
    m[13] = "kumar";

    m.insert({5, "bheem"});

    for (auto i: m) {
        cout << i.first << " " << i.second << endl; // Sorted Order
    }
    
    cout << "Finding 13 -> " << m.count(13) << endl;

    auto it = m.find(5);

    for (auto i = it; i != m.end(); i++) {
        cout << (*i).first << endl;
    }
    
    return 0;
}