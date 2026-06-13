class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // variable size sliding window having sum k = arr_sum-x

        int arr_sum = accumulate(nums.begin(), nums.end(), 0);
        int k = arr_sum - x; // target sum

        if (k < 0)
            return -1; // no valid subarray exists

        int i = 0, j = 0, sum = 0, maxLen = INT_MIN;
        while (j < nums.size()) {
            sum += nums[j];
            if (sum == k) {
                maxLen = max(maxLen, j - i + 1);
            }
            if (sum > k) {
                while (sum > k) {
                    sum -= nums[i];
                    i++;
                    if (sum == k) {
                        maxLen = max(maxLen, j - i + 1);
                    }
                }
            }
            j++;
        }
        return maxLen == INT_MIN ? -1 : nums.size() - maxLen;
    }
};