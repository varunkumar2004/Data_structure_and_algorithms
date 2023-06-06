#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> intoVector(int sum) {
    int factor = 10;
    int i = 1;
    vector<int> v;

    while(sum % factor > 0) {
        sum = sum / factor;
        factor *= 10;
        i++;
    }

    for (int j = 0; j < i; j++) {
        v.push_back(sum / pow(factor, i - 1));
    }
    

    return v;
}

vector<int> sumOfArrays(vector<int> arr1, vector<int> arr2) {
    int i = 0, j = 0;
    int n = arr1.size(), m = arr2.size();
    int sum1 = 0, sum2 = 0;

    while (i < n) {
        sum1 += arr1[n - 1 - i] * pow(10, i);
        i++;
    }

    while (j < m) {
        sum2 += arr2[m - 1 - j] * pow(10, j);
        j++;
    }
    
    return intoVector(sum1 + sum2);
}

void printArray(vector<int> arr) {
    cout << "Array is: ";

    for (int a : arr) {
        cout << a << endl;
    }
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {6};
    vector<int> arr3;
    arr3 = sumOfArrays(arr1, arr2);
    printArray(arr3);

    return 0;
}