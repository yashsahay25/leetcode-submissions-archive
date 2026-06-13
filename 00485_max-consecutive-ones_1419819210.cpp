class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // if 0, then count 0 else count is also 1
        int consec = nums[0], maxCount = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 0) {
                consec = 0;
            } else {
                if (nums[i - 1] == 0)
                    consec = 1;
                else if (nums[i - 1] == 1)
                    consec++;
            }
            maxCount = max(maxCount, consec);
        }
        return maxCount;
    }
};