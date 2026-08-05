class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // pahle adjacency list bana lo
        vector<vector<int>> adj(n);
        for (auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        // method k se BFS karke suspicious set nikal lo
        vector<bool> suspicious(n, false);
        suspicious[k] = true;
        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push(v);
                }
            }
        }

        // check karo: koi non-suspicious method suspicious ko invoke to nahi karta
        bool canRemove = true;
        for (auto& inv : invocations) {
            int a = inv[0], b = inv[1];
            if (!suspicious[a] && suspicious[b]) {   // <-- fixed condition
                canRemove = false;
                break;
            }
        }

        vector<int> result;
        if (!canRemove) {
            for (int i = 0; i < n; i++) result.push_back(i);
        } else {
            for (int i = 0; i < n; i++)
                if (!suspicious[i]) result.push_back(i);
        }
        return result;
    }
};