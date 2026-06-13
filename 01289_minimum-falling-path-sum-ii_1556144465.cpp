class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp = grid;
        vector<int> next = grid[n - 1]; // for next row

        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(n); // current row
            for (int j = 0; j < n; j++) {
                int minSum = INT_MAX;
                for (int k = 0; k < n; k++) {
                    if (k != j) {
                        minSum = min(minSum, next[k]);
                    }
                }
                curr[j] = grid[i][j] + minSum;
            }
            next = curr;
        }
        return *min_element(next.begin(), next.end());
    }
};