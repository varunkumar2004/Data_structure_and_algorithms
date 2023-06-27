#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int> &stack, int num) {
    // base case
    if(stack.empty() || (!stack.empty() && stack.top() < num)) {
        stack.push(num);
        return;
    }

    int n = stack.top();
    stack.pop();

    // recursive call
    sortedInsert(stack, n);

    stack.push(n);
}

void sortedStack(stack<int> &stack) {
    if(stack.empty()) {
        return;
    }

    int num = stack.top();
    stack.pop();

    // recursive call
    sortedStack(stack);

    sortedInsert(stack, num);
}

void print(stack<int> s) {
    if(s.empty()) return;

    int x = s.top();

    s.pop();

    print(s);
    cout << x << " ";
    s.push(x);
}

int main() {
    stack<int> stack;
    stack.push(2);
    stack.push(10);
    stack.push(1);
    stack.push(0);
    stack.push(-5);

    sortedStack(stack);
    print(stack);
    return 0;
}