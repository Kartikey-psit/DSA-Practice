class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // f: undirected graph for connectivity check
        // g: directed graph for finding suspicious methods
        vector<vector<int>> f(n), g(n);
        vector<bool> suspicious(n, false);
        vector<bool> vis(n, false);

        // Build graphs
        for (const auto& e : invocations) {
            int a = e[0], b = e[1];
            f[a].push_back(b);
            f[b].push_back(a); // Undirected
            g[a].push_back(b); // Directed
        }

        // Lambda for First DFS: Mark all methods reachable from k as suspicious
        auto dfs = [&](this auto&& self, int i) -> void {
            suspicious[i] = true;
            for (int j : g[i]) {
                if (!suspicious[j]) {
                    self(j);
                }
            }
        };

        // Execute First DFS
        dfs(k);

        // Lambda for Second DFS: Check connectivity from non-suspicious nodes
        auto dfs2 = [&](this auto&& self, int i) -> void {
            vis[i] = true;
            for (int j : f[i]) {
                if (!vis[j]) {
                    // If we reach a suspicious node from a non-suspicious one,
                    // it means the suspicious group is NOT isolated.
                    // We mark it back to false (keep it).
                    suspicious[j] = false; 
                    self(j);
                }
            }
        };

        // Execute Second DFS from all non-suspicious, unvisited nodes
        for (int i = 0; i < n; ++i) {
            if (!suspicious[i] && !vis[i]) {
                dfs2(i);
            }
        }

        // Collect results
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (!suspicious[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};   
