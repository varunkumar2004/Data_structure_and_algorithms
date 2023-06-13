#include <iostream>
using namespace std;

void sayDigits(int n, string arr[10])
{
    if (n == 0)
        return;

    // int ans = printDigits(n % );
    int digit = n % 10;
    n = n / 10;

    sayDigits(n, arr);
    cout << arr[digit] << " ";
}

int main()
{
    string arr[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n;
    cout << "Enter number: ";
    cin >> n;

    sayDigits(n, arr);
    return 0;
}