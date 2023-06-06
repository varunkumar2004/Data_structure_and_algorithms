#include <iostream>
#include <vector>
using namespace std;

// To find an element in an array using binary search
int binarySearch(vector<int>& arr, int key) {
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s) / 2;

    while(s <= e) {
        if(arr[mid] == key) {
            return mid;
        }else if(key > arr[mid]) {
            s = mid + 1;
        }else {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    cout << "Index: " << binarySearch(arr, 4);
    return 0;
}