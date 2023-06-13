#include <iostream>
using namespace std;

bool binarySearch(int *arr, int start, int end, int key)
{
    if (start > end)
        return false;

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
        return true;

    if (arr[mid] < key)
        return binarySearch(arr, mid + 1, end, key);
    else
        return binarySearch(arr, start, mid - 1, key);
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int key;
    cout << "Enter the key: ";
    cin >> key;

    int index = binarySearch(arr, 0, 5, key);
    cout << index << endl;
    return 0;
}