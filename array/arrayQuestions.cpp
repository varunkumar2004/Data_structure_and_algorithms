#include <iostream>
#include <vector>
using namespace std;

vector<int> reverseArray(vector<int>& arr) {
    int s = 0, e = arr.size() - 1;

    while (s <= e) {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    
    return arr;
}

void printVector(vector<int>& arr) {
    cout << "Vector is: ";

    for (int i: arr) {
        cout << i << " ";
    }

    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    
    arr = reverseArray(arr);
    printVector(arr);
    return 0;
}