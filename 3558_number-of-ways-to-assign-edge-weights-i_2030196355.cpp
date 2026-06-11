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
    int dfs(int node, int parent, const vector<vector<int>>& adj) {
        int maxHeight = 0;

        for (int child : adj[node]) {
            // Prevent moving backwards to the parent node
            if (child != parent) {
                maxHeight = max(maxHeight, 1 + dfs(child, node, adj));
            }
        }

        return maxHeight;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>> adj(n);
        for(auto& e:edges){
            int u = e[0]-1;
            int v = e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Initial parent is set to -1 since the root has no parent
        int treeHeight = dfs(0, -1, adj);
        
        // number of cominations where sum is ODD = 2^(n-1)
        return modPow(2, treeHeight - 1);
    }
};