class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp = grid;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int minSum = INT_MAX;
                for (int k = 0; k < n; k++) {
                    if (k != j) {
                        minSum = min(minSum, dp[i + 1][k]);
                    }
                }
                dp[i][j] += minSum;
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};