#include <iostream>
#include <string>
using namespace std;

string replaceSpaces(string &str) {
    // string temp = "";

    for (int i = 0; i < str.length(); i++) {
        if(str[i] == ' ') {
            str.replace(i, 1, "@40");
        }
    }

    return str;
}

int main() {
    string str;
    cout << "Enter string: ";
    getline(cin, str);

    str = replaceSpaces(str);
    cout << "New string: " << str << endl;
    return 0;
}