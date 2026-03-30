class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0); // using Kahn's algo

        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);

            for (auto& nbr : adj[node]) {
                indegree[nbr]--;

                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        // false → cycle exists, so can't finish
        return res.size() == n ? res : vector<int>{};
    }
};