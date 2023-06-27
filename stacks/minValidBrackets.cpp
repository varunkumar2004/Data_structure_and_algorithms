#include <iostream>
#include <stack>
using namespace std;

int findMinimumCost(string str) {

    if (str.length() % 2 != 0) return -1;
    stack<char> stack;
    
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if (ch == '(') stack.push(ch);
        else {
            if (!stack.empty() && stack.top() == '(') stack.pop();
            else stack.push(ch);
        }

        int a = 0, b = 0;
        // while()
    }
}

int main() {
    return 0;
}