class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> matrix;

        // create jagged rows in matrix
        for (int i = 0; i < numRows; i++) {
            vector<int> currRow(i + 1, 1); // row i has i+1 columns
            matrix.push_back(currRow);
        }
        // 1st, 2nd row already settled, start from 3rd row
        for (int i = 2; i < numRows; i++) {
            for (int j = 1; j < matrix[i].size() - 1; j++) {
                matrix[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j];
            }
        }
        return matrix;
    }
};