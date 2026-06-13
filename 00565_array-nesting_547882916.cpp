class Solution {
public:
    void dfs(int node,vector<int> &vis,vector<int> adj[],int &count)
    {
        vis[node]=1;
        count++;
        for(auto it:adj[node])
            if(!vis[it])
                dfs(it,vis,adj,count);
    }
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            if(i!=nums[i])
                adj[i].push_back(nums[i]);
        }
        vector<int> vis(n,0);
        int mx=0;
        for(int i=0;i<n;i++)
        {
            int count=0;
            if(!vis[i])
                dfs(i,vis,adj,count);
            mx=max(mx,count);
        }
        return mx;
    }
};