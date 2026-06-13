class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(matrix[n - 1]); // Copy last row as base case

        for (int i = n - 2; i >= 0; i--) { // Start from second-last row
            vector<int> curr(n);
            for (int j = 0; j < n; j++) {
                int down = prev[j];
                int downLeft = (j > 0) ? prev[j - 1] : INT_MAX;
                int downRight = (j < n - 1) ? prev[j + 1] : INT_MAX;

                curr[j] = matrix[i][j] + min({down, downLeft, downRight});
            }
            prev = curr;
        }

        return *min_element(prev.begin(), prev.end()); // Minimum in first row
    }
};