#include <iostream>
#include <vector>
using namespace std;

int peakIndexMountain(vector<int> &arr) {
    int s = 0;
    int e = arr.size();
    int mid = s + (e - s) / 2;

    while (s < e) {
        if (arr[mid] < arr[mid + 1]) {
            s = mid + 1;
        }else {
            e = mid;
        }

        mid = s + (e - s) / 2;
    }

    return s;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    return 0;
}