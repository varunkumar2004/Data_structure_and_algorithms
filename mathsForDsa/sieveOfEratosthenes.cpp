#include <bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes 
vector<int> countPrimes(int n) {
    int count = 0;
    vector<int> primes;

    // step 1 : Marks every number as prime number
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++) {
        if(prime[i]) {
            count++;
            primes.push_back(i);

            // step 2 : Marks multilpes of i(instance) as non prime
            for(int j = i * i; j < n; j = j + i) {
                prime[j] = false;
            }
        }
        
    }

    return primes;
}

void printArray(vector<int> arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int key;
    vector<int> primes;
    cout << "Enter the number: ";
    cin >> key;

    primes = countPrimes(key);
    printArray(primes);
    return 0;
}