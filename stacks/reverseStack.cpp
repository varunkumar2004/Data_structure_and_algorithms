#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x) {
    if(s.empty()) {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();
    
    insertAtBottom(s, x);
    s.push(num);
}

void reverseStack(stack<int> &s) {
    // base case
    if(s.empty()) return;

    int num = s.top();
    s.pop();
    reverseStack(s);

    insertAtBottom(s, num);
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
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    reverseStack(s);
    print(s);
    return 0;
}