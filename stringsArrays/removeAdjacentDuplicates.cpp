#include <iostream>
using namespace std;

bool areDuplicates(string &str) {
    int alpha[26] = {0};

    for (int i = 0; i < str.length() - 1; i++) {
        int index = str[i] - 'a';
        alpha[index]++;
    }

    for (int i = 0; i < 26; i++) {
        if(alpha[i] >= 2) {
            return true;
        }
    }
    
    return false;
}

string removeAdjacentDuplicates(string &str) {
    int index = 0;

    while(areDuplicates(str)) {
        for (int i = 0; i < str.length(); i++) {
            if(str[i] == str[i + 1]) {
                str.erase(str.begin() + i, str.begin() + i + 2);
                index++;
            }
        }
    }

    return str;
}

int main() {
    string str = "azxxzy";

    str = removeAdjacentDuplicates(str);
    cout << str << endl;
    return 0;
}