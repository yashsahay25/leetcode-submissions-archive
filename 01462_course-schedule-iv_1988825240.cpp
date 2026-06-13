class Solution {
public:
    void dfs(int src, int node, vector<int>& visited, vector<vector<int>>& adj,
             vector<vector<int>>& path) {
        visited[node] = 1;   // mark node as visited
        path[src][node] = 1; // mark path A-->B (keep src same)

        for (auto nbr : adj[node])
            if (!visited[nbr])
                dfs(src, nbr, visited, adj, path);
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }

        // path[i][j] denotes if path exists between i & j
        vector<vector<int>> path(n, vector<int>(n, 0));

        // precompute & store for each node
        for (int i = 0; i < n; i++) {
            // fresh visited array for each node
            vector<int> visited(n, 0);

            // do dfs, no visited check required
            dfs(i, i, visited, adj, path);
        }

        int q = queries.size();
        vector<bool> result(q, false);
        for (int i = 0; i < q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            // directly check status from precomputed path matrix
            if (path[u][v] == 1)
                result[i] = true;
        }
        return result;
    }
};