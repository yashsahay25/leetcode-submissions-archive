class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // optimal approach 1 - Xor
        
        int n = nums.size();
        int xorSum = 0;
        for (int i = 0; i <= n; i++) {
            xorSum = xorSum^i;
        }
        for (int num : nums) {
            xorSum = xorSum^num;
        }
        return xorSum;

        // optimal approach 2 - sum
        
        // int n = nums.size();
        // int expectedSum = (n * (n + 1)) / 2; --> might cause overflow
        // int actualSum = accumulate(nums.begin(), nums.end(), 0);
        // return expectedSum - actualSum;
    }
};