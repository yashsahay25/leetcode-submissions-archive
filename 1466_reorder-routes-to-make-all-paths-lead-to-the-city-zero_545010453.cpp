class Solution {
public:
    vector<pair<int,int>>adj[50000];
    bool vis[50000];
    int ans = 0;
    void dfs(int x)
    {
        vis[x] = true;
        for(auto it:adj[x])
        {
            if(!vis[it.first])
            {
                if(it.second==1)    //checks if edge from i to it exists in forward dir.
                    ans++;
                dfs(it.first);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        memset(vis, false, sizeof(vis));
        for(int i=0; i<connections.size(); ++i)
		{
            adj[connections[i][0]].push_back({connections[i][1], 1});
			adj[connections[i][1]].push_back({connections[i][0], 0}); 
		}
        dfs(0);
        return ans;
    }
};