#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &s, int x) {
    if (s.empty()) {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();
    solve(s, x);
    s.push(num);
}

stack<int> pushAtBottom(stack<int> &s, int x) {
    // base case
    solve(s, x);
    return s;
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    pushAtBottom(s, 0);
    return 0;
}