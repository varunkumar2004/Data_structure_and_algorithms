#include <iostream>
using namespace std;

bool isSorted(int *arr, int size)
{
    if (size == 0 || size == 1)
        return true;

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool ans = isSorted(arr + 1, size - 1);
        return ans;
    }
}

int sumOfArray(int *arr, int size)
{
    if (size == 0)
        return 0;

    if (size == 1)
        return arr[0];

    int result = arr[0] + sumOfArray(arr + 1, size - 1);
    return result;
}

int binarySearch()
{
    return 1;
}

int main()
{
    int arr[4] = {1, 2, 3, 4};
    int sort = isSorted(arr, 4);
    int sum = sumOfArray(arr, 4);

    cout << sort << endl;
    return 0;
}