class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        int n = mat.size();
        int m = mat[0].size();

        if (j < 0 || j >= m)
            return INT_MAX;
        if (i == n - 1)
            return mat[i][j];

        if (dp[i][j] != -2)
            return dp[i][j];

        int dl = solve(i + 1, j - 1, mat, dp);
        int d = solve(i + 1, j, mat, dp);
        int dr = solve(i + 1, j + 1, mat, dp);

        return dp[i][j] = mat[i][j] + min({dl, d, dr});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), minSum = INT_MAX;

        vector<vector<int>> dp(n, vector<int>(m, -2));
        for (int j = 0; j < m; j++) {
            minSum = min(minSum, solve(0, j, matrix, dp));
        }
        return minSum;
    }
};