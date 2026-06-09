class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0), suffix(n, 0);
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i + 1];
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(abs(prefix[i] - suffix[i]));
        }
        return res;
    }
};