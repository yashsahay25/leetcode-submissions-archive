class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dungeon,
              vector<vector<int>>& dp) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        if (i >= m || j >= n) // base case (out of bounds)
            return INT_MAX;

        if (i == m - 1 && j == n - 1) // base case (reach the end)
            return max(1, 1 - dungeon[i][j]);

        if (dp[i][j] != -1)
            return dp[i][j];

        // minHealthNeeded at (i,j) depends on right & down.
        // so first calculate them & then decide
        int healthReqdRight = solve(i, j + 1, dungeon, dp);
        int heathReqdLeft = solve(i + 1, j, dungeon, dp);

        int minHealthNeeded =
            min(healthReqdRight, heathReqdLeft) - dungeon[i][j];

        return dp[i][j] = max(1, minHealthNeeded);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, dungeon, dp);
    }
};