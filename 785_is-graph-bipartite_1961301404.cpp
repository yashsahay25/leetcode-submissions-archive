class Solution {
public:
    bool dfs(int node, int c, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = c;
        for (int nbr : graph[node]) {
            // agar neighbor unvisited hai
            if (color[nbr] == -1) {
                // usko opposite color kar do
                if (!dfs(nbr, 1 - c, color, graph)) {
                    return false;
                }
            }
            // agar already visited hai aur same color hai → conflict
            else if (color[nbr] == c) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        // traverse for all nodes to cover all not-connected components
        for (int i = 0; i < n; i++) {
            // if not visited, then do dfs
            if (color[i] == -1 && !dfs(i, 0, color, graph)) {
                return false;
            }
        }
        return true;
    }
};