class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        int n = grid.size();
        if (i == n - 1)
            return grid[i][j];

        if (dp[i][j] != -2)
            return dp[i][j];
        int minSum = INT_MAX;
        for (int k = 0; k < n; k++) {
            if (k != j) {
                minSum = min(minSum, grid[i][j] + solve(i + 1, k, grid, dp));
            }
        }
        return dp[i][j] = minSum;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dp(n, vector<int>(n, -2));
        int minSum = INT_MAX;
        for (int j = 0; j < n; j++) {
            minSum = min(minSum, solve(0, j, grid, dp));
        }
        return minSum;
    }
};