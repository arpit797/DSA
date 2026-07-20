class Solution {
public:
    bool solve(unordered_map<int,vector<int>>& adj, int src, int dest, vector<bool>& vis) {
        if (src == dest)
            return true;

        if (vis[src])
            return false;

        vis[src] = true;

        for (int node : adj[src]) {
            if (solve(adj, node, dest, vis))
                return true;
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        unordered_map<int, vector<int>> adj;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);

        return solve(adj, src, dest, vis);
    }
};