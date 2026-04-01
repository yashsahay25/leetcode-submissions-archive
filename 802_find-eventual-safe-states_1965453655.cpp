class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> revGraph(n);
        vector<int> outdegree(n, 0);

        // Step 1: Build reverse graph + outdegree
        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                revGraph[v].push_back(u);
            }
            outdegree[u] = graph[u].size();
        }

        // Step 2: Push terminal nodes (outdegree = 0)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safe;

        // Step 3: Kahn's Algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for (auto nbr : revGraph[node]) {
                outdegree[nbr]--;

                if (outdegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        // Step 4: Sort result
        sort(safe.begin(), safe.end());
        return safe;
    }
};