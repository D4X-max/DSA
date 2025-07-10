#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    bool detect(int src, vector<int> adj[], vector<int>& vis) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjacentNode : adj[node]) {
                if (!vis[adjacentNode]) {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                } else if (adjacentNode != parent) {
                    // Cycle found
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(i, adj, vis))
                    return true;
            }
        }
        return false;
    }
};

// -----------------------------
// Example Driver Code
// -----------------------------
int main() {
    int V = 5;  // Number of vertices
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},  // This forms a cycle
        {3, 4}
    };

    // Convert edge list to adjacency list
    vector<int> adj[V];
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // because it's an undirected graph
    }

    Solution obj;
    bool ans = obj.isCycle(V, adj);
    
    if (ans)
        cout << "Graph contains a cycle" << endl;
    else
        cout << "Graph does not contain a cycle" << endl;

    return 0;
}
