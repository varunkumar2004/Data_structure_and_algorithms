#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// find first negative number in window of 2 in queue
// Approach 1 -> using deque
vector<long long> findNegative(long long int A[], long long int N, long long int K) {
    deque<long long int> dq;
    vector<long long> ans; 

    // process first window of k size
    for (int i = 0; i < K; i++) {
        if (A[i] < 0) 
            dq.push_back(i);
    }

    // store ans of first k sized window
    if (dq.size() > 0) {
        ans.push_back(A[dq.front()]);
    } else {
        ans.push_back(0);
    }

    // process for remaining windows
    for (int i = 0; i < N; i++) {
        if (!dq.empty() && i - dq.front() >= K) {
            dq.pop_front();
        }

        if (A[i] < 0) {
            dq.push_back(i);
        }

        if (dq.size() > 0) {
            ans.push_back(A[dq.front()]);
        } else {
            ans.push_back(0);
        }
    }

    return ans;
}

int main() {
    long long int A[] = {-8, 2, 3, -6, 10};
    vector<long long> v;

    v = findNegative(A, 5, 2);
    return 0;
}