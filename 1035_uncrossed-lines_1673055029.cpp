class Solution {
public:
    int solve(vector<int>& a, vector<int>& b, int i, int j,
              vector<vector<int>>& dp) {
        // base case
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        // recurrence
        if (a[i] == b[j]) {
            return dp[i][j] = 1 + solve(a, b, i - 1, j - 1, dp);
        } else {
            int skipI = solve(a, b, i - 1, j, dp);
            int skipJ = solve(a, b, i, j - 1, dp);
            return dp[i][j] = max(skipI, skipJ);
        }
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(nums1, nums2, n - 1, m - 1, dp);
    }
};