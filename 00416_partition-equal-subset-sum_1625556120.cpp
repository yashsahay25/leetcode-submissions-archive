class Solution {
public:
    bool solve(vector<int>& nums, int index, int target, vector<vector<int>>& dp) {
        if (target == 0)    return true;
        if (index == 0)     return nums[0] == target;

        if(dp[index][target]!=-1) return dp[index][target];

        bool notPick = solve(nums, index - 1, target, dp);
        bool pick = (target >= nums[index])
                        ? solve(nums, index - 1, target - nums[index], dp)
                        : false;
        return dp[index][target] = pick || notPick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int k = sum/2;
        vector<vector<int>> dp(n,vector<int> (k+1,-1));
        return sum % 2 == 0 ? solve(nums, n - 1, k, dp) : false;
    }
};