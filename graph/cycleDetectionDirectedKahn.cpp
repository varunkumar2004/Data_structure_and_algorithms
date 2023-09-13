#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

int cycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adj[u].push_back(v);
    }

    vector<int> indegree(n);
    for (auto i: adj) {
        for (auto j: i.second) {
            indegree[j]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    int count = 0;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        count++;

        // neighbour degree update
        for (auto neighbour: adj[front]) {
            indegree[neighbour]--;

            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    if (count == n) {
        return false;
    } else return true;
}

int main() {
    return 0;
}