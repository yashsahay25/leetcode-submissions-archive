class Solution {
public:
    bool solve(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (nums[0] <= sum) dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= sum; j++) {
                bool notPick = dp[i - 1][j];

                bool pick = (j >= nums[i]) ? dp[i - 1][j - nums[i]] : false;

                dp[i][j] = pick || notPick;
            }
        }
        return dp[n - 1][sum];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int k = sum / 2;
        return sum % 2 == 0 ? solve(nums, k) : false;
    }
};