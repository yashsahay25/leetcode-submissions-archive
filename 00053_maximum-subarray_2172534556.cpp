class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // subarray can't be empty, so we start with 1st element as sub-array itself
        int runningSum = nums[0], maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // if current element increases runningSum --> extend the subarray
            // else, reset runningSum
            runningSum = max(nums[i], runningSum + nums[i]);
            maxSum = max(maxSum, runningSum);
        }
        return maxSum;
    }
};

/*
runningSum +ve, nums[i] +ve --> extend
runningSum -ve, nums[i] +ve --> start new subarray with current element
runningSum +ve, nums[i] +ve --> extend
runningSum -ve, nums[i] -ve --> start new subarray
*/