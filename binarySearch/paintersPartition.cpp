#include <iostream>
#include <vector>
using namespace std;

// Same as book allocation problem
bool isPossible(vector<int> &arr, int n, int m, int mid) {
    int paintersCount = 1;
    int timeSum = 0;

    for(int i = 0; i < n; i++) {
        if(timeSum + arr[i] <= mid) {
            timeSum += arr[i];
        }else {
            paintersCount++;
            if(paintersCount > m || arr[i] > mid) {
                return false;
            }

            timeSum = arr[i];
        }
    }
    
    return true;
}

int paintingPartition(vector<int>& arr, int n, int m) {
    int s = 0;
    int sum = 0;
    int ans = -1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int e = sum;
    int mid = s + (e - s) / 2;

    while(s <= e) {
        if(isPossible(arr, n, m, mid)) {
            ans = mid;
            e = mid - 1;
        }else {
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}


int main() {
    int testCases;
    int n, m;
    int input;
    vector<int> arr;

    cin >> testCases;

    while(testCases--) {
        cin >> n >> m;
        
        for(int i = 0; i < n; i++) {
            cin >> input;
            arr.push_back(input);
        }

        cout << paintingPartition(arr, n, m) << endl; 
    }

    return 0;
}