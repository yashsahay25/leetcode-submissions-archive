class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // dp states -> i, j1, j2
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, 0)));

        // base case
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                dp[n - 1][j1][j2] = j1 == j2
                                        ? grid[n - 1][j1]
                                        : grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {

                    int maxCherries = 0;

                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {

                            int cherries = j1 == j2 ? grid[i][j1]
                                                    : grid[i][j1] + grid[i][j2];

                            int newJ1 = j1 + dj1;
                            int newJ2 = j2 + dj2;

                            if (newJ1 >= 0 && newJ1 < m && newJ2 >= 0 && newJ2 < m)
                                cherries += dp[i + 1][newJ1][newJ2];

                            maxCherries = max(maxCherries, cherries);
                        }
                    }
                    dp[i][j1][j2] = maxCherries;
                }
            }
        }
        return dp[0][0][m - 1];
    }
};