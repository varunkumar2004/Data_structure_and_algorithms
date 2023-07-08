#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> reverseWords(vector<char> str) {
    reverse(str.begin(), str.end());
    int n = str.size();
    int j = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        if(str[i] == ' ' || str[i] == '\0') {
            reverse(str.begin() + j, str.begin() + i);
            j = i + 1;
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
    vector<char> str = {'n', 'a', 'm', 'a', 'n', ' ', 'v', 'a', 'r', 'u', 'n'};

    str = reverseWords(str);
    printString(str);
    return 0;
}