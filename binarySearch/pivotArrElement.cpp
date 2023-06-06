#include <iostream>
#include <vector>
using namespace std;

// To find finding a particular element in rotated array
int binarySearch(vector<int>& arr, int s, int e, int key) {
    int start = s;
    int end = e;
    int mid = start + (end - start) / 2;

    while (start <= end) {
        if (arr[mid] == key) {
            return mid;
        }else if (key > arr[mid]) {
            start = mid + 1; // go to right part
        }else {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return -1;
}

int getPivotIndex(vector<int>& arr) {
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s)/ 2;

    while(s <= e) {
        if(arr[mid] >= arr[0]) {
            s = mid + 1;
        }else {
            e = mid;
        }

        mid = s + (e - s) / 2;
        return s;
    }
}

int getPivotedElement(vector<int>& arr, int key) {
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    int pivotIndex = getPivotIndex(arr);

    while(s <= arr.size()) {
        if(key >= arr[pivotIndex] && key <= arr[arr.size() - 1]) {
            return binarySearch(arr, pivotIndex, arr.size() - 1, key);
        }else {
            return binarySearch(arr, 0, pivotIndex - 1, key);
        }
    }
}

int main() {
    vector<int> arr = {8, 10, 18, 1, 3};
    int pivot = getPivotedElement(arr, 18);

    cout << "Point is at Index: " << pivot << endl;
    return 0;
}