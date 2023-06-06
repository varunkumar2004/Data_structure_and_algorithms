#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> reverseWords(vector<char> str) {
    int n = str.size();
    int j = 0;

    for (int i = 0; i < n - 1; i++) {
        if(str[i] == ' ') {
            reverse(str.begin() + j, str.begin() + i);
            j = i + 1;
        }else if (str[i] == '\0') {
            reverse(str.begin() + j, str.begin() + i);
            j = i;
        }
    }

    return str;
}

void printString(vector<char> str) {
    int n = str.size() - 1;

    cout << "String is: ";
    for (size_t i = 0; i < n; i++) {
        cout << str[i] << " ";
    }
}

int main() {
    vector<char> str = {'t', 'h', 'e', ' ', 'v', 'a', 'r', 'u', 'n'};
    str = reverseWords(str);
    printString(str);
    return 0;
}