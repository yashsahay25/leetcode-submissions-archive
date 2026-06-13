class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> dp(n, 0);

        // Initialize last cell
        dp[n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);

        // Fill the last row (right to left)
        for (int j = n - 2; j >= 0; j--) {
            dp[j] = max(1, dp[j + 1] - dungeon[m - 1][j]);
        }

        // Process the remaining rows
        for (int i = m - 2; i >= 0; i--) {
            dp[n - 1] = max(1, dp[n - 1] - dungeon[i][n - 1]); // Last column
            for (int j = n - 2; j >= 0; j--) {
                int minHealthOnExit = min(dp[j], dp[j + 1]);
                dp[j] = max(1, minHealthOnExit - dungeon[i][j]);
            }
        }

        return dp[0];
    }
};