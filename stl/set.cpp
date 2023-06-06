#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(0);
    s.insert(6); // Only one copy of elements gets stored
    s.insert(6);

    for(int a: s) {
        cout << a << " "; // Sorted output
    }

    cout << endl;

    s.erase(s.begin());
    for (int a : s) {
        cout << a << " ";
    }

    cout << "Is 5 present or not -> " << s.count(5) << endl;
}