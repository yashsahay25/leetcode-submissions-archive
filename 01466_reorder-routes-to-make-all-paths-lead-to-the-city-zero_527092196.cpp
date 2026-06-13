class Solution {
public:
    vector<pair<int,int>>adj[50000];
    bool vis[50000];
    int ans = 0;
    void dfs(int x)
    {
        vis[x] = true;
        for(int i=0; i<adj[x].size(); ++i)
            if(!vis[adj[x][i].first])
            {
                if(adj[x][i].second == 1)
                    ++ans;
                dfs(adj[x][i].first);
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