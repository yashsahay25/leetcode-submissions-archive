class Solution {
public:
    int jump(vector<int>& nums) {
        // greedy approach - try to reach the farthest possible element
        int n = nums.size();

        int jumps = 0, currEnding = 0, maxReachable = 0;
        // currEnding is the ending value of current possible jumps from i

        for (int i = 0; i < n - 1; i++) {
            // update the farthest reachable position for each index
            maxReachable = max(maxReachable, i + nums[i]);

            // if we have reached the index which is ending of this jump
            // or, if we have explored all possible reachable index from i
            if (i == currEnding) {
                jumps++;
                currEnding = maxReachable;
            }
        }
        return jumps;
    }
};