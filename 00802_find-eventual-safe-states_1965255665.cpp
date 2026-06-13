class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& path,
             vector<vector<int>>& graph) {
        vis[node] = 1;
        path[node] = 1;

        for (auto nbr : graph[node]) {
            if (!vis[nbr] && dfs(nbr, vis, path, graph))
                return true;
            else if (path[nbr] == 1)
                return true;
        }
        path[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // DFS - 2 array recursion path tracking approach
        int n = graph.size();

        vector<int> visited(n, 0);
        vector<int> path(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, path, graph);
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (path[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};