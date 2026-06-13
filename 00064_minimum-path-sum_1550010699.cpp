class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> prev(n, 0);

            for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    curr[j] = grid[i][j];
                else {
                    int up = (i > 0) ? prev[j] : INT_MAX;
                    int left = (j > 0) ? curr[j - 1] : INT_MAX;
                    curr[j] = grid[i][j] + min(up, left);
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};