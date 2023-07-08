#include <bits/stdc++.h>
using namespace std;

string merge(string str1, string str2) {
    string merged;
    int n = str1.length(), m = str2.length();
    int j = 0, k = 0;
    
    for(int i = 0; i < (n + m); i++) {
        if(i % 2 == 0) {
            merged.push_back(str1[j]);
            j++;
        }else {
            merged.push_back(str2[k]);
            k++;
        }   
    }

    return merged;
}

int main() {
    string str1 = "hello";
    string str2 = "varun";
    string str3;
    str3 = merge(str1, str2);

    cout << str3 << endl;
    return 0;
}