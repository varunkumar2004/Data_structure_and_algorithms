#include <iostream>
#include <vector>
using namespace std;

// Doubles it's capacity when filled 
int main() {
    vector<int> v = {1, 2, 3, 4};
    cout << "Size: " << v.capacity() << endl;
    v.pop_back();
    v.clear();

    vector<int> arr(5, 1);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}