#include<bits/stdc++.h>
 
#define fastio; ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 
void solve(vector<vector<int>>& adj, int Q) {
    int n = adj.size(), k = 1;
    vector<int> numChildreen(n), res(n), indexOf(n);
    
    function<int(int)> dfs;
    dfs = [&](int node) {
        int subNodes = 0, idx = k;
        k++;
        res[idx] = node;
        indexOf[node] = idx;
        for (int adjNode: adj[node]) {
            subNodes += dfs(adjNode);
        }
        numChildreen[node] = subNodes + 1;  //to check
        return (subNodes + 1);
    };
    dfs(1);
    
    for (int i = 0; i < Q; i++) {
        int u, k;
        cin >> u >> k;
        if (k > numChildreen[u]) {
            cout << -1;
        }
        else {
            int lastIdx = indexOf[u] + k - 1;
            cout << res[lastIdx] << " ";
        }
        cout << endl;
    }
}
 
int main() {
    fastio;
    int V, Q, temp;
    cin >> V >> Q;
    V++;
    vector<vector<int>> adj(V);
    for (int i = 2; i < V; i++) {
        cin >> temp;
        adj[temp].push_back(i);
    }
    solve(adj, Q);
    return 0;
}