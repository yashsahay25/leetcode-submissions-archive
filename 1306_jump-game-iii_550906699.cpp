class Solution {
public:
    bool dfs(int i,vector<int>& arr,vector<bool> &vis)
    {
        if(i<0 or i>= arr.size() or vis[i]) return false;
        
        if(arr[i]==0)   return true;
        vis[i]=true;
        return dfs(i+arr[i],arr,vis) || dfs(i-arr[i],arr,vis);
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> vis(n,0);
        return dfs(start,arr,vis);
    }
};