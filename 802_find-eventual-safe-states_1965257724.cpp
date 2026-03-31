class Solution {
public:
    bool dfs(int node, vector<int>& state, vector<vector<int>>& graph) {
        state[node] = 1;

        for (auto nbr : graph[node]) {
            if (state[nbr]==0 && dfs(nbr, state, graph))
                return true;
            else if (state[nbr] == 1)
                return true;
        }
        state[node] = 2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // DFS - single state array approach
        int n = graph.size();

        vector<int> state(n, 0);

        for (int i = 0; i < n; i++) {
            if (state[i] == 0) {
                dfs(i, state, graph);
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (state[i] == 2) {
                res.push_back(i);
            }
        }
        return res;
    }
};