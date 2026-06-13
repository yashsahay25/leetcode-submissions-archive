class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int lastPosition = n - 1; // intially lastPosition is last index
        for (int i = n - 2; i >= 0; i--) { // traverse R to L
            if (i + nums[i] >=
                lastPosition) { // if last can be reached from prev index
                lastPosition = i;
            }
        }
        return (lastPosition == 0);
    }
};