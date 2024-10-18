#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int>& ls) {
    vis[node] = 1;
    ls.push_back(node);
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis, ls);
        }
    }
}

vector<int> doDFS(vector<int> adj[], int n) {
    int visited[n + 1] = {};
    vector<int> ls;
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, ls);
        }
    }
    
    return ls;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    
    vector<int> trav = doDFS(adj, n);
    for (auto it : trav) {
        cout << it << " ";
    }
}
// 8 8 
// 1 2 
// 2 5 
// 2 6 
// 1 3 
// 3 4 
// 3 7 
// 7 8 
// 8 4