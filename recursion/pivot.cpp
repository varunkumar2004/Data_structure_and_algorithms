#include <iostream>
#include <vector>
using namespace std;

int getPivotIndex(vector<int> &arr, int start, int end)
{
    if (start > end)
        return -1;

    if (start == end)
        return start;

    int mid = start + (end - start) / 2;

    if (mid < end && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > start && arr[mid] < arr[mid - 1])
        return mid - 1;
    if (arr[start] >= arr[mid])
        return getPivotIndex(arr, start, mid - 1);

    return getPivotIndex(arr, mid + 1, end);
}

int binarySearch(vector<int> &arr, int start, int end, int key)
{
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
        return mid;
    if (arr[mid] < key)
        binarySearch(arr, mid + 1, end, key);

    return binarySearch(arr, start, mid - 1, key);
}

int findElementInPivotedArray(vector<int> &arr, int n, int key)
{
    int pivot = getPivotIndex(arr, 0, n - 1);

    if (pivot == -1)
        return binarySearch(arr, 0, n - 1, key);

    if (arr[pivot] == key)
        return pivot;

    if (arr[0] <= key)
        return binarySearch(arr, 0, pivot - 1, key);

    return binarySearch(arr, pivot + 1, n - 1, key);
}

int main()
{
    vector<int> arr = {4, 5, 1, 2, 3};
    int n = arr.size();
    int index = findElementInPivotedArray(arr, n, 2);
    cout << index << endl;
    return 0;
}