class Solution {
public:

    long long modPow(long long a, long long b) {
        long long MOD = 1e9+7;
        long long ans = 1;

        while (b) {
            if (b & 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return ans;
    }
    int bfs(const vector<vector<int>>& adj, int n){
        queue<pair<int,int>> q; // {node, depth}
        vector<bool> vis(n + 1, false);

        q.push({1, 0});
        vis[1] = true;

        int maxDepth = 0;

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            maxDepth = max(maxDepth, depth);

            for (int nbr : adj[node]) {
                if (!vis[nbr]) {
                    vis[nbr] = true;
                    q.push({nbr, depth + 1});
                }
            }
        }

        return maxDepth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>> adj(n+1);
        for(auto& e:edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int treeHeight = bfs(adj,n);
        
        // number of cominations where sum is ODD = 2^(n-1)
        return modPow(2, treeHeight - 1);
    }
};