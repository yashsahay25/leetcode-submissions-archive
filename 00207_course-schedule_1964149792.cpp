class Solution {
public:
    // question boils down to whether a topo sort exists or not
    // ie. there should be no cyclic dependency
    // we have to detect cycle in the directed graph
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
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

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto& nbr : adj[node]) {
                indegree[nbr]--;

                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        return count == n; // false → cycle exists, so can't finish
    }
};