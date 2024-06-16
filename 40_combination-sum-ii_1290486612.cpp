class Solution
{
    private:
        void solve(int index, vector<int> &current, int sum, vector<int> &nums, vector<vector < int>> &res)
        {
            if (sum == 0)
            {
                res.push_back(current);
                return;
            }
           	// backtrack over all choices
            for (int i = index; i < nums.size(); i++)
            {
               	// Skip duplicates
                if (i > index && nums[i] == nums[i - 1])
                    continue;

               	// break the loop condition (taken out to stop further
               	// iterations/backtrack)
                if (nums[i] > sum)
                    break;
                current.push_back(nums[i]);
                solve(i + 1, current, sum - nums[i], nums, res);
                current.pop_back();
            }
        }
public: 
    vector<vector < int>> combinationSum2(vector<int> &candidates,int target)
    {
        vector<vector < int>> res;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        solve(0, current, target, candidates, res);
        return res;
    }
};