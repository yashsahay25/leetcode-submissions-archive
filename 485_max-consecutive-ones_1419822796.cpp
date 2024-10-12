class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currCount = 0, maxCount = 0;
        for (int x : nums) {
            if (x == 1)
                currCount++;
            else
                currCount = 0;
            maxCount = max(maxCount, currCount);
        }
        return maxCount;
    }
};