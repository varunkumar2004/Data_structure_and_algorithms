#include <iostream>
#include <vector>
using namespace std;

vector<int> reverseSubArray(vector<int> arr, int index) {
    int s = index + 1, e = arr.size() - 1;

    while (s <= e) {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    
    return arr;
}

void printVector(vector<int> &arr) {
    cout << "Vector is: ";

    for (int i : arr) {
        cout << i << " ";
    }

    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    arr = reverseSubArray(arr, 3);
    printVector(arr);
    return 0;
}