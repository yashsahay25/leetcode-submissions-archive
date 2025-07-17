class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int len = 1, maxLen = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                len++;
                maxLen = max(maxLen, len);
            } else {
                len = 1;
            }
        }
        return maxLen;
    }
};