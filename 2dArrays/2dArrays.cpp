#include <bits/stdc++.h>
using namespace std;

bool isPresent(int arr[][4], int target, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] == target) {
                return 1;
            }
        }
    }

    return 0;
}

void largetSumRow(int arr[][4], int n, int m) { 
    int maxi = INT_MIN;
    int rowIndex = -1;

    for (int i = 0; i < n; i++) {
        int rowSum = 0;

        for (int j = 0; j < m; j++) {
            rowSum += arr[i][j];
        }

        if ((int)rowSum > maxi) {
            maxi = (int)rowSum;
            rowIndex = i;
        }
    }

    cout << "The maximum sum is " << maxi << endl;
}

void printWavePattern(int arr[][4], int row, int col) {
    for(int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if(i % 2 == 0) {
                cout << arr[j][i] << " ";
            }else {
                cout << arr[row - j - 1][i] << " ";
            }
        }
        
        cout << endl;
    }
}

void rowsSum(int arr[][4], int n, int m) {
    for (int i = 0; i < n; i++) {
        int rowSum = 0;

        for (int j = 0; j < m; j++) {
            rowSum += arr[i][j];
        }

        cout << rowSum << " ";
    }
}

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> newVector;
    int row = matrix.size();
    int col = matrix[0].size();

    int count = 0;
    int total = row * col;

    // indexes 
    int startRow = 0, startCol = 0;
    int endRow = row - 1, endCol = col - 1;

    while(count < total) {
        // print starting row
        for (int index = startRow; count < total && index <= endRow; index++) {
            newVector.push_back(matrix[startRow][index]);
            count++;
        }
        startRow++;

        // print ending col
        for (int index = startRow; count < total && index <= endRow; index++) {
            newVector.push_back(matrix[index][endCol]);
            count++;
        }
        endCol--;

        // print ending row
        for (int index = endCol; count < total && index >= startCol; index--) {
            newVector.push_back(matrix[endRow][index]);
            count++;
        }
        endRow--;

        // print starting col
        for (int index = endRow; count < total && index >= startRow; index--) {
            newVector.push_back(matrix[index][startCol]);
            count++;
        }
        startCol++;
    }

    return newVector;
}

void printArray(vector<int> arr) {
    cout << "Array is: ";

    for (int i = 0; i < arr.size() - 1; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<vector<int>> vec = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> newVec;

    // int target;
    // cout << "Enter element: ";
    // cin >> target;

    // if (isPresent(arr, target, 3, 4)) {
    //     cout << "Element Found" << endl;
    // }else {
    //     cout << "Element not Found" << endl;
    // }
    

    // rowsSum(arr, 3, 4);
    // printWavePattern(arr, 3, 4);

    newVec = spiralOrder(vec);
    printArray(newVec);
    return 0;
}