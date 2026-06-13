class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // base case
                if (i == m - 1 && j == n - 1) {
                    dp[i][j] = max(1, 1 - dungeon[i][j]);
                } // normal case
                else {
                    int healthReqdRight = (j + 1 < n) ? dp[i][j + 1] : INT_MAX;
                    int healthReqdDown = (i + 1 < m) ? dp[i + 1][j] : INT_MAX;

                    int minHealthNeeded =
                        min(healthReqdRight, healthReqdDown) - dungeon[i][j];
                    dp[i][j] = max(1, minHealthNeeded);
                }
            }
        }
        return dp[0][0];
    }
};