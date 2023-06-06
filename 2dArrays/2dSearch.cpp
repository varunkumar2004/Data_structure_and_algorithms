#include <bits/stdc++.h>
using namespace std;

bool linearSearchMatrix(vector<vector<int>> &matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    for(int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if(matrix[i][j] == target) {
                return 1;
            }
        }
    }

    return 0;
}

bool binarySearchSortedMatrix(vector<vector<int>> &matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();
    int s = 0, e = col * row - 1;
    int mid = s + (e - s) / 2;

    while(s <= e) {
        int element = matrix[mid / col][mid % col];
        if(element == target) {
            return 1;
        }else if(element > target) {
            s = mid + 1;
        }else {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return 0;
}

int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target;

    cout << "Enter target: ";
    cin >> target;
    cout << "Present or not: " << linearSearchMatrix(matrix, target);
    return 0;
}