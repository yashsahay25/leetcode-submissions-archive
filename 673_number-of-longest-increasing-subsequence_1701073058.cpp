class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        // dp[i] = Length of Longest Increasing Subsequence ending at index i
        vector<int> dp(n, 1);

        // count[i] = Number of LIS ending at index i
        vector<int> count(n, 1);

        int maxLen = 1; // Tracks the length of the overall LIS
        int res = 0;    // Final result: total number of LIS

        // Loop through each element to fill dp and count
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // Can we extend the subsequence ending at j?
                if (nums[i] > nums[j]) {
                    // Found a longer subsequence by adding nums[i]
                    if (1 + dp[j] > dp[i]) {
                        dp[i] = 1 + dp[j];   // Update LIS length at i
                        count[i] = count[j]; // Inherit count from j
                    }
                    // Found another subsequence of the same max length
                    else if (1 + dp[j] == dp[i]) {
                        count[i] += count[j]; // Add ways from j to i
                    }
                }
            }
            // Track the max LIS length found so far
            maxLen = max(maxLen, dp[i]);
        }

        // Now sum all counts where LIS length is equal to maxLen
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLen) {
                res += count[i];
            }
        }

        return res;
    }
};