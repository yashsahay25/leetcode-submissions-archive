class Solution {
public:
    bool dfs(int u, int v, vector<int>& visited, vector<vector<int>>& adj) {
        visited[u] = 1;

        for (auto nbr : adj[u]) {
            if (!visited[nbr]) {
                if (nbr == v) return true;
                if (dfs(nbr, v, visited, adj)) return true;
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }

        int q = queries.size();
        vector<bool> result(q, false);
        for (int i = 0; i < q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            vector<int> visited(numCourses, 0);
            if (dfs(u, v, visited, adj))
                result[i] = true;
        }
        return result;
    }
};