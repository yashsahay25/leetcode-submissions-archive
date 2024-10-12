class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currCount = 0, maxCount = 0;
        for (int x : nums) {
            if (x == 1)
                currCount++, maxCount = max(maxCount, currCount);
            else
                currCount = 0;
        }
        return maxCount;
    }
};