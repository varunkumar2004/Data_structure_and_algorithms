#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <list>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight) {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printAdj() {   
        for (auto i : adj) {
            cout << i.first << " -> ";

            for (auto j : i.second) {
                cout << "(" << j.first << ", " << j.second << ")";
            }

            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &vis, stack<int> &s) {
        vis[node] = true;

        for (auto neighbour: adj) {
            if (!vis[neighbour.first]) {
                dfs(neighbour.first, vis, s);
            }
        }

        s.push(node);
    }

    void getShortestPath(int src, vector<int> &dist, stack<int> &s) {
        dist[src] = 0;

        while (!s.empty()) {
            int top = s.top();
            s.pop();

            if (dist[top] != INT_MAX) {
                for (auto i : adj[top]) {
                    if (dist[top] + i.second < dist[i.first]) {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};

int main() {
    Graph g;
    int n = 6;
    unordered_map<int, bool> visited;
    stack<int> s;

    // topological sort
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            g.dfs(i, visited, s);
        }
    }

    int src = 1;
    vector<int> dist(n);

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    g.getShortestPath(src, dist, s);

    cout << endl;
    
    for (int i=0; i<dist.size(); i++) {
        cout << dist[i] << " ";
    }

    cout << endl;

    return 0;
}