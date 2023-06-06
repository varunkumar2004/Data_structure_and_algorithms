#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> s;
    s.push("Varun");
    s.push("Naman");

    cout << "Top Element: " << s.top() << endl;

    for (int i = 0; i < s.size(); i++) {
        s.pop();
    }
    
    return 0;
}