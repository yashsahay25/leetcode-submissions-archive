class Solution {
public:
    vector<bool> checkIfPrerequisite(int N, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        // adjacency matrix
        vector<vector<bool>> adj(N, vector<bool>(N, 0));
        for (auto& pre : prerequisites) {
            adj[pre[0]][pre[1]] = 1;
        }

        // floyd warshall algo
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
                }
            }
        }

        int q = queries.size();
        vector<bool> result(q, false);
        for (int i = 0; i < q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            // directly check path/reachability matrix
            if (adj[u][v] == 1)
                result[i] = 1;
        }
        return result;
    }
};