#include <iostream>
using namespace std;

int main() {
    int n, row, col;
    cout << "Enter row & col: ";
    cin >> row >> col;

    // // Square matrix creation
    // // int arr[5]; Static memory
    // int* arr = new int[n]; // Dynamic memory allocation
    // int** matrix = new int*[n];
    
    // for(int i = 0; i < n; i++) {
    //     matrix[i] = new int[n];
    // }   // Creation done

    // // Matrix input
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         matrix[i][j] = i + j;
    //     }
    // }

    // // Printing matrix values
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << matrix[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    // Non-Sqaure matrix creation
    int** matrix = new int*[row];

    for(int i = 0; i < row; i++) {
        matrix[i] = new int[col];
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            matrix[i][j] = i + j;
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    // Releasing memory
    for(int i = 0; i < row; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;

    return 0;
}