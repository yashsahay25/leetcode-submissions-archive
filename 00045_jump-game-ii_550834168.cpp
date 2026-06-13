class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)    return 0;
        if(nums[0]==0)  return 0;
        int jumps=0,currReachable=0,maxReachable=0;
        
        for(int i=0;i<n-1;i++)
        {
            maxReachable = max(maxReachable,i+nums[i]);
            if(i==currReachable)
            {
                jumps++;
                currReachable = maxReachable;
            }
        }
        return jumps;
    }
};