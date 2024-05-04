class Solution
{
    public:
        bool searchMatrix(vector<vector < int>> &matrix, int target)
        {
           	// flatten the 2d matrix into imaginaary 1d matrix
           	// actual flattening is costly due to O(N*M) time
            int n = matrix.size();
            int m = matrix[0].size();

            int lo = 0, hi = n*m - 1;
            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;
                int row = mid / m, col = mid % m;

                if (matrix[row][col] == target)
                    return true;
                else if (matrix[row][col] > target)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            return false;
        }
};