#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

vector<pair<pair<int,int>,int>> prims(int n,int m, vector<pair<pair<int,int>,int>> &g) {
    // create adjacency list
    unordered_map<int,list<pair<int,int>>> adj;
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first; // firstnode
        int v = g[i].first.second; // secondnode
        int w = g[i].second; // weight
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> parent(n+1);
    vector<int> mst(n+1);
    vector<int> key(n+1);

    for (int i = 0; i <=n ; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // start of algo from here
    key[1] = 0; // source node
    parent[1] = -1;

    for (int i = 1; i < n; i++) {
        int mini = INT_MAX;
        int u;

        for (int v = 1; v <= n; v++) {
            if (mst[v] == false && key[v] < mini) {
                mini = key[v];
                u = v;
            }
        }

        // mark min node as true
        mst[u] = true;

        // check its adjacent node
        for (auto i: adj[u]) {
            int v = i.first;
            int w = i.second;

            if (mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int,int>,int>> result;
    for (int i = 2; i <=n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}

int main() {
    return 0;
}