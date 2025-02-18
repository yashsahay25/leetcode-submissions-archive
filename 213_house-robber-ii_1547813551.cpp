class Solution {
public:
    int solve(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int prev = 0, prev2 = 0;
        for (int i = l; i <= r; i++) {
            int curr = max(nums[i] + prev2, prev);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
};