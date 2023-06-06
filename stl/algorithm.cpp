#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout << binary_search(v.begin(), v.end(), 6) << endl; // True or False
    cout << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl;
    cout << upper_bound(v.begin(), v.end(), 4) - v.begin() << endl;

    int a = 3, b = 5;
    cout << "Max -> " << max(a, b) << endl;
    cout << "Min -> " << min(a, b) << endl;

    swap(a, b); 

    string abcd = "abcd";
    reverse(abcd.begin(), abcd.end());
    cout << "String -> " << abcd << endl;

    rotate(v.begin(), v.begin() + 1, v.end());

    cout << "After rotate: ";
    for(int a: v) {
        cout << a << " ";
    }

    return 0;
}