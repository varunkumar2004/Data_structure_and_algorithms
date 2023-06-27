#include <iostream>
using namespace std;

void findMinTurns(int limit, int &count) {
    // base case 
    if (limit == 1) {
        cout << "No of ways: " << count << endl;
        return;
    }

    if (limit % 2 == 0) 
        findMinTurns(limit / 2, ++count);
    else 
        findMinTurns(limit - 1, ++count);
}

int main() {
    int count = 0;
    int limit, ans;

    cout << "Enter limit: ";
    cin >> limit;

    findMinTurns(limit, count);
    return 0;
}