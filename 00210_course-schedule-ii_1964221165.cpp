class Solution {
public:
    // state: 0 - not visited, 1 - visiting (in path), 2 - visited
    bool dfs(int node, vector<int>& state, vector<int> adj[], vector<int>& res) {
        state[node] = 1;

        for (auto nbr : adj[node]) {
            if (state[nbr] == 0) {
                if (dfs(nbr, state, adj, res) == true)
                    return true;
            } else if (state[nbr] == 1)
                return true;
        }
        res.push_back(node);
        state[node] = 2;
        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> state(n, 0);
        vector<int> res;

        for (int i = 0; i < n; i++) {
            if (state[i] == 0) {
                if (dfs(i, state, adj, res))
                    return {};
            }
        }
        reverse(res.begin(),res.end()); // instead we can use a stack as well
        return res;
    }
};