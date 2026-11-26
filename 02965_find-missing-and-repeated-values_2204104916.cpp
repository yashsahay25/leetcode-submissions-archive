class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long N = n * n;

        long long actualSum = 0;
        long long actualSquareSum = 0;

        // Accumulate the two actual totals using wide integers.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long long num = grid[i][j];
                actualSum += num;
                actualSquareSum += num * num;
            }
        }

        long long expectedSum = N * (N + 1) / 2;
        long long expectedSquareSum = N * (N + 1) * (2 * N + 1) / 6;
        long long difference = actualSum - expectedSum;

        long long sumOfAnswers =
            (actualSquareSum - expectedSquareSum) / difference;

        // Use the sum and difference of the answers to find both numbers.
        long long repeating = (difference + sumOfAnswers) / 2;
        long long missing = repeating - difference;

        return {(int)repeating, (int)missing};
    }
};