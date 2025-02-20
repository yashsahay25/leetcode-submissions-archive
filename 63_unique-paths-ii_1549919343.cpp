class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j,
              vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || grid[i][j])
            return 0;

        if (i == 0 && j == 0)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = solve(grid, i - 1, j, dp) + solve(grid, i, j - 1, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(obstacleGrid, m - 1, n - 1, dp);
    }
};