class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int currSum = 0, maxSum = nums[0];
        for (int i = 0; i < n; i++) {
            currSum += nums[i];
            maxSum = max(currSum, maxSum);
            if (currSum < 0)
                currSum = 0;
        }
        return maxSum;
    }
};