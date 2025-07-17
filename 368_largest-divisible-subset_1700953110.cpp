class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        if (n == 1) return nums;

        // sort the array so that we don't have to check both i%j & j%i
        sort(nums.begin(), nums.end());

        // prev vector to track the index which extends susbet at i 
        // (similar to LIS)
        vector<int> dp(n, 1), prev(n, -1);
        int maxLen = 1, lastIndex = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // if nums[j] divides nums[i], so we can extend subset at j
                // and new seq len = 1+dp[j] is more, we update dp[i]
                if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    prev[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        // print logic
        // NOTE: dry run yourself to understand this better
        vector<int> res;
        while (lastIndex != -1) {
            res.push_back(nums[lastIndex]);
            lastIndex = prev[lastIndex];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};