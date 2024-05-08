class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            int target = 0 - nums[i];
            int lo = i + 1, hi = nums.size() - 1;

            while (lo < hi) {
                int sum = nums[lo] + nums[hi];
                if (sum < target)
                    lo++;
                else if (sum > target)
                    hi--;
                else if (sum == target) {
                    res.push_back({nums[i], nums[lo], nums[hi]});
                    lo++, hi--;

                    // skip duplicates
                    while (lo < hi && nums[lo] == nums[lo - 1])
                        lo++;
                    while (lo < hi && nums[hi] == nums[hi + 1])
                        hi--;
                }
            }
        }
        return res;
    }
};