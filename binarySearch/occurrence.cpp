#include <iostream>
#include <vector>
using namespace std;

// To find first and last occurrence of an element in an array
int firstOcc(vector<int>& arr, int key) {
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    int ans;

    while(s <= e) {
        if(arr[mid] == key) {
            ans = mid;
            e = mid - 1;
        }else if(key > arr[mid]) {
            s = mid + 1;
        }else {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}

int lastOcc(vector<int>& arr, int key) {
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e) {
        if (arr[mid] == key) {
            ans = mid;
            s = mid + 1;
        }else if (key > arr[mid]) {
            s = mid + 1;
        }else if (key < arr[mid]) {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}

int main() {
    return 0;
}