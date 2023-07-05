#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// reverese first k elements in a queue
// Approach -> using stacks

queue<int> reverseFirstKElements(queue<int> &q, int k) {
    // step 1: pop first k from q and put into stack
    stack<int> s;

    for (int i = 0; i < k; i++) {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // step 2: fetch from stack and push into queue
    while (!s.empty()) {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    // step 3: fetch first n - k element from queue and push_back
    int t = q.size() - k;

    while (t--) {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}

int main() {
    return 0;
}