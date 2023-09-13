#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

// Dijkstra's shortest path
vector<int> dijkstraAlgo(vector<vector<int>> &vec, int vertices, int edges, int src) {
    // create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i=0; i<edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // creation of distance array with infinte value initially
    vector<int> dist(vertices);
    for (int i=0; i<vertices; i++) {
        dist[i] = INT_MAX;
    }

    set<pair<int, int>> st;
    dist[src] = 0;
    st.insert(make_pair(0, src));

    while (!st.empty()) {
        // fetch auto record
        auto top = *(st.begin());
        int nodeDist = top.first;
        int topNode = top.second;

        // remove top record
        st.erase(st.begin());

        for (auto neighbour: adj[topNode]) {
            if (nodeDist + neighbour.second < dist[neighbour.first]) {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                // if record found then erase it
                if (record != st.end()) {
                    st.erase(record);
                }

                dist[neighbour.first] = nodeDist + neighbour.second;
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist;
}

int main() {
    return 0;
}