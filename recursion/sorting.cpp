#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr, int n)
{
    if (n <= 1)
        return;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }

    bubbleSort(arr, n - 1);
}

void insertionSort(vector<int> &arr, int n)
{
    if (n <= 1)
        return;

    insertionSort(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last;
}

int minIndex(vector<int> &arr, int i, int j)
{
    if (i == j)
        return i;

    int k = minIndex(arr, i + 1, j);
    return (arr[i] < arr[k]) ? i : k;
}

void selectionSort(vector<int> &arr, int n, int index = 0)
{
    if (index == n)
        return;

    int k = minIndex(arr, index, n - 1);

    if (k != index)
        swap(arr[k], arr[index]);

    selectionSort(arr, n, index + 1);
}

void printVector(vector<int> &arr)
{
    cout << "Vector is: ";

    for (int i : arr)
        cout << i << " ";

    cout << endl;
}

int main()
{
    vector<int> arr1 = {2, 5, 1, 6, 9};
    vector<int> arr2 = {2, 5, 1, 6, 9};
    vector<int> arr3 = {2, 5, 1, 6, 9};
    bubbleSort(arr1, arr1.size());
    insertionSort(arr2, arr2.size());
    selectionSort(arr3, arr3.size());

    printVector(arr3);

    return 0;
}