#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// # Approach 1 -> using two loops {Time Complexity === O(n ^ 2)}

// # Approach 2 -> using stacks
vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> stack;
    stack.push(-1);
    vector<int> ans(n);

    for(int i = n - 1; i >= 0; i--) {
        int curr = arr[i];

        while(stack.top() >= curr) {
            stack.pop();
        }

        ans[i] = stack.top();
        stack.push(curr);
    }

    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr, int n) {
    // reverse of nextSmallerElement
    return arr;
}

void printVector(vector<int> arr) {
    cout << "Array: ";

    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
    vector<int> arr = {2, 1, 4, 3};
    arr = nextSmallerElement(arr, arr.size());
    printVector(arr);
    return 0;
}