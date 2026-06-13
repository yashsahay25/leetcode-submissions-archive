class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // a + b + c = 0
        // b + c = -a
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            // skip iteration if duplicate at i found
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            int a = -nums[i];

            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum == a) {
                    res.push_back({-a, nums[j], nums[k]});
                    j++;
                    k--;

                    // skip duplicates
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                } else if (sum > a) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return res;
    }
};