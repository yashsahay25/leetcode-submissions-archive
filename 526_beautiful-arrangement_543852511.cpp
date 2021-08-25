class Solution {
public:
    int solve(vector<int>&nums, vector<int>&vis, int index, int n)
    {
        if(index==n+1){
            return 1;
        }
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            if(!vis[nums[i]] && (nums[i]%index==0 || index%nums[i]==0))
            {
                vis[nums[i]]=1; //mark
                res+=solve(nums,vis,index+1,n); //solve
                vis[nums[i]]=0; //backtrack / unmark
            }
        }
        return res;
    }
    int countArrangement(int n) 
    {
        vector<int>nums, vis(n+1,0);
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        
        return solve(nums,vis,1,n);
    }
};