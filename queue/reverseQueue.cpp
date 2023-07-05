#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Approach 1 -> using stacks
queue<int> reverse(queue<int> q) {  
    stack<int> s;

    while (!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while (!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }

    return q;
}

// Approach 2 -> using recursion
void reverseQueue(queue<int> &q) {
    if (q.empty()) return;

    int element = q.front();
    q.pop();
    reverseQueue(q);
    q.push(element);
}

void printQueue(queue<int> q) {
    while(!q.empty()) {
        int element = q.front();
        cout << element << " ";
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    reverseQueue(q);
    printQueue(q);
    return 0;
}