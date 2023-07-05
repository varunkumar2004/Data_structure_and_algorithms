#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> interweiveQueue(queue<int> &q) {
    int size = q.size();
    int count = 0;
    stack<int> nStack;

    while (count < (size / 2)) {
        int val = q.front();
        q.pop();
        nStack.push(val);
        count++;
    }

    while (!nStack.empty()) {
        int val = nStack.top();
        nStack.pop();
        q.push(val);
    }

    while (count < size) {
        int val = q.front();
        q.pop();
        q.push(val);
        count++;
    }

    count = 0;

    while (count < (size / 2)) {
        int val = q.front();
        q.pop();
        nStack.push(val);
        count++;
    }

    while (!nStack.empty()) {
        int val = nStack.top();
        nStack.pop();
        q.push(val);

        int val2 = q.front();
        q.pop();
        q.push(val2);
    }

    return q;
}

void print(queue<int> q) {
    cout << "Queue: ";

    while (!q.empty()) {
        int val = q.front();
        q.pop();
        cout << val << " ";
    }

    cout << endl;
}

void print(stack<int> s) {
    cout << "Stack: ";

    while (!s.empty()) {
        int val = s.top();
        s.pop();
        cout << val << " ";
    }

    cout << endl;
}

int main() {
    queue<int> q;
    stack<int> s;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    
    q = interweiveQueue(q);
    print(q);
    return 0;
}