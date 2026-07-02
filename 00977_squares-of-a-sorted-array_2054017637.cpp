class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int l = 0, r = n - 1;

        int j = n - 1;
        while (l <= r && j >= 0) {
            int lSquare = nums[l] * nums[l];
            int rSquare = nums[r] * nums[r];

            if (lSquare < rSquare) {
                ans[j] = rSquare;
                r--;
            } else {
                ans[j] = lSquare;
                l++;
            }
            j--;
        }
        return ans;
    }
};