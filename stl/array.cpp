#include <iostream>
#include <array>
using namespace std;

int main() {
    int basic[3] = {1, 2, 3};
    array<int, 4> arr = {1, 2, 3, 4};

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }

    cout << "Element at 2 is: " << arr.at(2) << endl;
    cout << "Empty or not: " << arr.empty() << endl;
    cout << "First Element: " << arr.front() << endl;
    cout << "Last Element: " << arr.back() << endl;

    return 0;
}