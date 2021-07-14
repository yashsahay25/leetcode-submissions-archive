void dfs(int node,vector<int> adj[],vector<bool> & vis)
{
    vis[node]=true;
    for(auto it:adj[node])
        if(!vis[it])
            dfs(it,adj,vis);
}
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        //n - no of vertices
        vector<int> adj[n]; 
        for(auto v:connections)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        if(connections.size() < n-1)   //not possible case
            return -1;
        vector<bool> vis(n, false);
        int k = 0;  //number of components
        for(int i=0; i<n; i++)
            if(!vis[i])
            {
                dfs(i,adj, vis);
                k++;
            }
        return k - 1;
    }
};