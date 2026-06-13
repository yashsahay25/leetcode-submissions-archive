class Solution {
public:
    bool bfs(int src, vector<int>& color, vector<vector<int>>& graph) {
        queue<int> q;

        color[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nbr : graph[node]) {
                // agar neighbor unvisited hai
                if (color[nbr] == -1) {
                    // usko opposite color kar do
                    color[nbr] = 1 - color[node];
                    q.push(nbr);
                }
                // agar already visited hai aur same color hai → conflict
                else if (color[nbr] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        // traverse for all nodes to cover all not-connected components
        for (int i = 0; i < n; i++) {
            // if not visited, then do bfs
            if (color[i] == -1 && !bfs(i, color, graph)) {
                return false;
            }
        }
        return true;
    }
};