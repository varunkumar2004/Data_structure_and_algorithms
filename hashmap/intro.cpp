#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

template <class T>
void print(T m) {
    // random order if unordered map is used
    class T :: iterator it = m.begin();
    while (it != m.end()) {
        cout << it->first << " " << it->second << endl;
        it++;
    }
}

int main() {
    // creation
    unordered_map<string, int> m;

    // insertion
    pair<string, int> p = make_pair("babbar", 3);
    pair<string, int> pair2 = make_pair("love", 2);

    m.insert(p);
    m.insert(pair2);

    m["mera"] = 1;
    m["mera"] = 2;

    // searching
    // cout << m.at("nothing") << endl; // error
    // cout << m["nothing"] << endl; // display 0

    // size 
    // cout << m.size() << endl;

    // check particular key is present or not
    // cout << m.count("bro") << endl; // 0 -> absent && 1 -> present

    print(m);
    
    return 0;
}