#include <iostream>
using namespace std;

bool linearSearch(int *arr, int size, int key)
{
    if (size == 0)
        return false;

    if (arr[0] == key)
        return true;
    else
    {
        bool ans = linearSearch(arr + 1, size - 1, key);
        return ans;
    }
}

int main()
{
    int arr[5] = {2, 3, 4, 5, 6};
    int key = 4;

    // cout << "Enter key: ";
    // cin >> key;

    bool isPresent = linearSearch(arr, 5, key);

    if (isPresent)
        cout << "Element Present" << endl;
    else
        cout << "Element Not Present" << endl;

    return 0;
}