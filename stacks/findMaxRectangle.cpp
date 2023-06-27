#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// # Approach 1 -> Brute Force using 2 loops Time { Complexity -> O(n ^ 2) }

// # Approach 2 -> using stacks
vector<int> nextSmallerElement(vector<int> arr, int n) {
    stack<int> stack;
    stack.push(-1);
    vector<int> ans(n);

    for(int i = n - 1; i >= 0; i--) {
        int curr = arr[i];

        while(stack.top() != - 1 && arr[stack.top()] >= curr) {
            stack.pop();
        }

        ans[i] = stack.top();
        stack.push(i);
    }

    return ans;
}

vector<int> prevSmallerElement(vector<int> arr, int n) {
    stack<int> stack;
    stack.push(-1);
    vector<int> ans(n);

    for(int i = 0; i >= n; i++) {
        int curr = arr[i];

        while(stack.top() != - 1 && arr[stack.top()] >= curr) {
            stack.pop();
        }

        ans[i] = stack.top();
        stack.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);
    int area = INT_MIN;

    for(int i = 0; i < n; i++) {
        int l = heights[i];
        if(next[i] == -1) next[i] = n;

        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area  = max(area, newArea);
    }

    return area;
}



int main() {
    vector<int> heights;
    largestRectangleArea(heights);
    return 0;
}