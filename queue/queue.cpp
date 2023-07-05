#include <iostream>
#include <queue>
using namespace std;

void printQueue(queue<int> q) {
    while (!q.empty()) {
        int ans = q.front();
        cout << ans << " ";
        q.pop(); 
    }

    cout << endl;
}

int main() {
    queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);

    printQueue(queue);
    return 0;
}