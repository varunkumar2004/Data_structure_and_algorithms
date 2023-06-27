#include <iostream>
#include <stack>
using namespace std;

bool findRedundantBrackets(string &expression) {
    stack<char> stack;

    for(int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        if (ch == '/' || ch == '+' || ch == '*' || ch == '-' || ch == '(') {
            stack.push(ch);
        }else {
            if (ch == ')') {
                bool isRedundant = true;

                while(stack.top() != '(') {
                    char top = stack.top();
                    if (top == '/' || top == '+' || top == '*' || top == '-') {
                        isRedundant = false;
                    }

                    stack.pop();
                }

                if (isRedundant == true)
                    return true;

                stack.pop();
            }   
        }
    }

    return false;
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
    string expression = "(a * b + (c / d))";
    string expression2 = "(a)";
    bool isRedundant = findRedundantBrackets(expression2);
    cout << "isRedundant: " << isRedundant << endl;
    return 0;
}