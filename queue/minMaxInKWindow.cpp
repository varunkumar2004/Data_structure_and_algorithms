#include <iostream>
#include <queue>
using namespace std;

int solve(int *arr, int n, int k) {
    deque<int> maxi(k);
    deque<int> mini(k);

    // addition of first k size window
    for (int i = 0; i < k; i++) {
        while (!maxi.empty() && maxi.back() <= arr[i])
            maxi.pop_back();
        
        while (!mini.empty() && mini.back() >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += arr[maxi.front()] + arr[mini.front()];

        while (!maxi.empty() && i - maxi.front() >= k) {
            maxi.pop_front();
        }

        while (!mini.empty() && i - maxi.front() >= k) {
            mini.pop_front();
        }
    }
}

int main() {
    int arr[7] = {2, -5, -1, 7, -3, -1, -2};
    cout << solve(arr, 7, 4) << endl; 
    return 0;
}