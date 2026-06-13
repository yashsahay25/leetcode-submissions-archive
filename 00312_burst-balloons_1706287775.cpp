class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size(); // original_size + 2
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // state variables
        // i = 1 to n-2, j=n-2 to 1 (but not less than i)
        // so in tabulation, we use reverse order

        // steps
        // 1 declare dp array, take care of index endings
        // 2 write the base case
        // 3 copy the recurrence
        // 4 return answer similar to memo code
        for (int i = n - 2; i >= 1; i--) {
            for (int j = i; j <= n - 2; j++) {
                int maxCoins = 0;
                for (int k = i; k <= j; k++) {
                    int coins = nums[i - 1] * nums[k] * nums[j + 1] +
                                dp[i][k - 1] + dp[k + 1][j];
                    maxCoins = max(maxCoins, coins);
                }
                dp[i][j] = maxCoins;
            }
        }
        return dp[1][n - 2];
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return solve(nums);
    }
};