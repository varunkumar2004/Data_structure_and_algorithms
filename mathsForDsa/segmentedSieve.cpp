#include <bits/stdc++.h>
using namespace std;

void simpleSieve(int n, vector<int> primes) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            primes.push_back(i);
            
            for (int j = i * i; j < n; j = j + i) {
                prime[j] = false;
            }
        }
    }

    for (int p = 2; p < n; p++) {
        if (prime[p] == true) {
            prime.push_back(p);
            cout << p << " ";
        }
    }
}

void segmented_sieve(int n) {
    int limit = floor(sqrt(n)) + 1;
    vector<int> prime(limit);   
    
    simpleSieve(limit, prime);

    int low = limit;
    int high = 2 * limit;

    while(low < n) {
        if(high >= n) {
            high = n;
        }

        vector<bool> mark(limit + 1, true);

        for(int i = 0; i < prime.size(); i++) {
            int loLim = floor(low / prime[i]) * prime[i];

            if (loLim < low) {
                loLim += prime[i];
            }

            for (int j = loLim; j < high; j += prime[i])
                mark[j - low] = false;
        }

        for (int i = low; i < high; i++)
            if (mark[i - low] == true)
                cout << i << " ";

        low = low + limit;
        high = high + limit;
    }

}

void printArray(vector<int> arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int target;
    cout << "Enter target: ";
    cin >> target;

    vector<int> primes;
    // primes = simpleSieve(target, primes);
    segmented_sieve(target);

    return 0;
}