class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, l = 0, r = 0;
        while (r < nums.size() - 1) {
            int maxReachableIndex = 0; // initialise
            // determine maxReachableIndex for our range [l,r]
            for (int i = l; i <= r; i++) {
                maxReachableIndex = max(maxReachableIndex, i + nums[i]);
            }
            // update range [l,r]
            l = r + 1;
            r = maxReachableIndex;
            jumps++; // increment jumps
        }
        return jumps;
    }
};