class Solution {
public:
    void generateSubsets(vector<int>& nums, int index, vector<int>& currentSubset, vector<vector<int>>& result) {
        result.push_back(currentSubset); // to push initial empty set

        for (int i = index; i < nums.size(); ++i) {
            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            currentSubset.push_back(nums[i]);
            generateSubsets(nums, i + 1, currentSubset, result);
            currentSubset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the input to handle duplicates
        vector<vector<int>> result;
        vector<int> currentSubset;
        generateSubsets(nums, 0, currentSubset, result);
        return result;
    }
};