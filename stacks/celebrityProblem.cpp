#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Celebrity -> knows no one
// But all know about celebrity

// # Approach 1 -> using brute force { Time Complexity O(n ^ 2) }

// # Approach 2 -> using stacks
bool knows(vector<vector<int>> &M, int a, int b, int n) {
    if (M[a][b] == 1) return true;
    return false;
}

int celebrity(vector<vector<int>> &M, int n) {
    stack<int> stack;

    // push all elements in stack
    for(int i = 0; i < n; i++) {
        stack.push(i);
    }

    while (stack.size() > 1) {
        int a = stack.top();
        stack.pop();

        int b = stack.top();
        stack.pop();

        if (knows(M, a, b, n)) stack.push(b);
        else stack.push(a);
    }

    int candidate = stack.top();

    // step 3 : single element in stack potential celebrity
    // row check
    int zeroCount = 0;

    for (int i = 0; i < n; i++) {
        if (M[candidate][i] == 0) zeroCount++;
    }

    if (zeroCount != n) return -1;

    // column check
    int oneCount = 0;

    for (int i = 0; i < n; i++) {
        if (M[i][candidate] == 1) oneCount++;
    }

    if (oneCount != n - 1) return -1;

    return candidate;
}


int main() {
    vector<vector<int>> M = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    int isCelebrity = celebrity(M, 3);
    cout << "celebrity: " << isCelebrity << endl;
    return 0;
}