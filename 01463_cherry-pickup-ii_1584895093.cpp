class Solution {
public:
    int solve(int i, int j1, int j2, vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();

        // Base case: out of bounds
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return 0;

        // Base case: reached the last row
        if (i == n - 1) {
            if (j1 == j2)
                return grid[i][j1]; // same cell, so return only once
            return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxCherries = 0;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int cherries =
                    j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                cherries += solve(i + 1, j1 + dj1, j2 + dj2, grid, dp);

                maxCherries = max(maxCherries, cherries);
            }
        }
        return dp[i][j1][j2] = maxCherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        // dp states -> i, j1, j2
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1)));

        return solve(0, 0, m - 1, grid, dp);
    }
};