class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        long long actualSum = 0;
        long long actualSquareSum = 0;

        // Accumulate the two actual totals using wide integers.
        for (long long num : nums) {
            actualSum += num;
            actualSquareSum += num * num;
        }

        long long expectedSum = n * (n + 1) / 2;
        long long expectedSquareSum = n * (n + 1) * (2 * n + 1) / 6;
        long long difference = actualSum - expectedSum;
        
        long long sumOfAnswers =
            (actualSquareSum - expectedSquareSum) / difference;

        // Use the sum and difference of the answers to find both numbers.
        long long repeating = (difference + sumOfAnswers) / 2;
        long long missing = repeating - difference;
        
        return {(int)repeating, (int)missing};
    }
};