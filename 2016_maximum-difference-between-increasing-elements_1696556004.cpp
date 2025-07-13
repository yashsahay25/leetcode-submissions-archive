class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = 0, minSoFar = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int diff = nums[i] - minSoFar;
            if (diff < 0) {
                diff = 0;
                minSoFar = nums[i];
                continue;
            }
            maxDiff = max(maxDiff, diff);
        }
        return maxDiff == 0 ? -1 : maxDiff;
    }
};