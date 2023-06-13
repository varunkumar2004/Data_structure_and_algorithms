#include <iostream>
#include <vector>
using namespace std;

int pivotSum(vector<int> &arr, int start, int end, int leftSum, int rightSum)
{
    if (start == end)
        return -1;

    if (start == end && leftSum == rightSum)
        return arr[start];

    if (rightSum > leftSum)
    {
        start++;
        leftSum += arr[start];
    }
    else
    {
        rightSum += arr[end];
        end--;
    }

    return pivotSum(arr, start, end, leftSum, rightSum);
}

int main()
{
    vector<int> arr = {1, 2, 5, 0, 3};
    int index = pivotSum(arr, 0, arr.size() - 1, 0, 0);
    cout << index << endl;
    return 0;
}