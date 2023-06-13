#include <iostream>
using namespace std;

void reverseString(string &str, int i, int j)
{
    if (i > j)
        return;

    swap(str[i], str[j]);
    i++;
    j--;
    reverseString(str, i, j);
}

bool checkPalindrome(string &str, int i, int j)
{
    if (i > j)
        return true;

    if (str[i] != str[j])
        return false;

    else
        return checkPalindrome(str, i++, j--);
}

int main()
{
    string name = "babbar";
    reverseString(name, 0, name.length() - 1);
    cout << name << endl;
    return 0;
}