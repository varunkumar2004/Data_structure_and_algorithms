#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
    // create adj
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // do bfs
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    parent[s] = -1;
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto i : adj[front]) {
            if (!visited[i]) {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    // prepare shortest path
    vector<int> ans;
    int currentNode = t;
    ans.push_back(t);

    while (currentNode != s) {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    // now reverse ans
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    return 0;
} 