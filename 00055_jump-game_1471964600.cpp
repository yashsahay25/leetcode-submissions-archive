class Solution {
public:
    bool canJump(vector<int>& nums) {
        // we try to find the max reachable index
        int maxReachableIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            // if i am checking for a position that cannot be reached, its false
            if (i > maxReachableIndex)
                return false;
            // next max index = i + nums[i]
            maxReachableIndex = max(maxReachableIndex, i + nums[i]);
            if (maxReachableIndex >= nums.size() - 1)
                return true; // if we cross last index
        }
        return true;
    }
};