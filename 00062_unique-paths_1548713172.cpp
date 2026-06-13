class Solution {
public:
    int count(int i, int j, vector<vector<int>>& dp) {
        // base case
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // recursion
        int left2right = count(i - 1, j, dp);
        int top2bottom = count(i, j - 1, dp);
        return dp[i][j] = left2right + top2bottom;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return count(m - 1, n - 1, dp);
    }
};