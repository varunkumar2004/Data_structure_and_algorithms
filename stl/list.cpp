#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l;
    list<int> n(l); // Copying one list to another 
    l.push_back(1);
    l.push_front(2);

    cout << "Before Erase: ";
    for(int i: l ){
        cout << i << " ";
    }

    l.erase(l.begin());
    cout << "\nAfter Erase: ";
    for (int i : l) {
        cout << i << " ";
    }

    return 0;
}