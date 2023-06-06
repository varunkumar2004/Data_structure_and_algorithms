#include <bits/stdc++.h>
using namespace std;

vector<int> rotate2DVector(int matrix[][3], int row, int col) {
    vector<int> vec;

    for (int i = 0; i < row; i++) {
        int j = col - 1;

        while (j >= 0) {
            vec.push_back(matrix[j][i]);
            j--;
        }
    }

    return vec;
}

void printArray(vector<int> arr) {
    cout << "Array is: ";

    for (int i = 0; i < arr.size() - 1; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> v;

    v = rotate2DVector(matrix, 3, 3);
    printArray(v);
    return 0;
}