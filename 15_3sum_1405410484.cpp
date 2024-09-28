class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            // skip iteration if duplicate at i found
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            int target = 0 - nums[i];
            int j = i + 1, k = nums.size() - 1;

            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum < target)
                    j++;
                else if (sum > target)
                    k--;
                else if (sum == target) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;

                    // skip duplicates
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return res;
    }
};