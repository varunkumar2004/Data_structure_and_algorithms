#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> d;
    d.push_back(1);
    d.push_front(3);
    d.push_front(2);

    for(int a : d) {
        cout << a << " ";
    }

    d.pop_back(); 
    d.pop_front();

    cout << endl;

    for (int a : d) {
        cout << a << " ";
    }

    d.erase(d.begin(), d.begin() + 1);

    return 0;
}