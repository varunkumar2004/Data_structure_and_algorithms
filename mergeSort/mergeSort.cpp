#include <iostream>
using namespace std;

void merge(int *arr, int s, int m, int e)
{
    int i, j, k;
    int n1 = m - s + 1;
    int n2 = e - m;

    int *first = new int[n1];
    int *second = new int[n2];

    for (int i = 0; i < n1; i++)
        first[i] = arr[s + i];

    for (int j = 0; j < n2; j++)
        second[j] = arr[m + 1 + j];

    // merge 2 sorted arrays
    i = 0, j = 0, k = s;

    while (i < n1 && j < n2)
    {
        if (first[i] <= second[j])
        {
            arr[k] = first[i];
            i++;
        }
        else
        {
            arr[k] = second[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        arr[k] = first[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = second[j];
        j++;
        k++;
    }

    delete[] first;
    delete[] second;
}

void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, mid, e);
}

int main()
{
    int arr[5] = {2, 5, 1, 6, 9};
    int n = 5;

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}