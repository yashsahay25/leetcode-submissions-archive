class Solution {
private:
    void backtrack(int index, int k, vector<int>& nums, vector<int> temp,
                   vector<vector<int>>& res) {
        if (index == nums.size()) {
            if (k == 0)
                res.push_back(temp);
            return;
        }
        // take
        if (k - nums[index] >= 0) {
            temp.push_back(nums[index]);                        // take
            backtrack(index, k - nums[index], nums, temp, res); // backtrack
            temp.pop_back();                                    // untake
        }
        // not take
        backtrack(index + 1, k, nums, temp, res); // backtrack
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(0, target, candidates, temp, res);
        return res;
    }
};