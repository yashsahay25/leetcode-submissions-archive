class Solution {
public:
    int maxMoney(int index, vector<int>& nums, vector<int>& dp) {
        if (index >= nums.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int pick = nums[index] + maxMoney(index + 2, nums, dp);
        int notPick = maxMoney(index + 1, nums, dp);
        return dp[index] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return maxMoney(0, nums, dp);
    }
};