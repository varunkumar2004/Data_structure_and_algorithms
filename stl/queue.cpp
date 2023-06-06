#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> q;
    q.push("Varun");
    q.push("Kumar");

    cout << "first element -> " << q.front() << endl;
    q.pop();
    cout << "first element -> " << q.front() << endl;

    cout << "Size after pop -> " << q.size() << endl;
    return 0;
}