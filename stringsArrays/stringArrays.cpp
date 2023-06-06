#include <iostream>
#include <cctype>
using namespace std;

bool validChar(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
        return 1;
    }

    return 0;
}

bool isPalindrome(char name[], int n) {    
    int s = 0, e = n - 1;

    // ignoring uppercase or lowercase
    while (s <= e) {
        if (tolower(name[s]) != tolower(name[e])) {
            return 0;
        }else {
            s++;
            e--;
        }
    }
    
    return 1;
}

bool validPalindrome(string str) {
    string temp = "";

    for (int j = 0; j < str.length(); j++) {
        if (validChar(str[j])) {
            temp.push_back(str[j]);
        }
    }    

    // convert to lower case
}

int getLength(char* name) {
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        count++;
    }
    
    return count;
}

void reverseString(char* name, int n) {
    int s = 0;
    int e = n - 1;

    while (s < e) {
        swap(name[s++], name[e--]);
    }
    
    cout << "Reverse string: " << name << endl;
}

int main() {
    char name[10];
    cout << "Enter string: ";
    cin.getline(name, 10);

    int len = getLength(name);

    reverseString(name, getLength(name));
    cout << "Is palindrome: " << isPalindrome(name, len) << endl;
    return 0;
}