class Solution {
public:
    // state: 0 - not visited, 1 - visiting (in path), 2 - visited
    bool dfs(int node, vector<int>& state, vector<int> adj[]) {
        state[node] = 1; // mark node as visiting

        for (auto nbr : adj[node]) {
            // if adjacent node is unvisited, call dfs
            if (state[nbr] == 0) {
                if (dfs(nbr, state, adj) == true)
                    return true;
            }
            // if adjacenet node is being visited (in same path)
            else if (state[nbr] == 1)
                return true;
        }
        state[node] = 2; // fully processed
        return false;    // no cycle found
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        // 0 - not visited, 1 - visiting (in path), 2 - visited
        vector<int> state(n, 0);

        for (int i = 0; i < n; i++) {
            if (state[i] == 0) {
                if (dfs(i, state, adj))
                    return false;
            }
        }
        return true;
    }
};