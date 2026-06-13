class Solution {
public:
    void dfs(int s,vector<vector<int>>& graph,vector<int>& vis)
    {
        vis[s]=1;
        for(int i=0;i<graph[s].size();i++)
        {
            if(i==s) continue;
            
            if(graph[s][i] && !vis[i])
                dfs(i,graph,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int count = 0;
        for(int i=0;i<n;i++)
            if(!vis[i])
            {
                dfs(i,isConnected,vis);
                count++;
            }
        return count;
    }
};