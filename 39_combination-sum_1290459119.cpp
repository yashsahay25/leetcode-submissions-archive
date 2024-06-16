class Solution {
private:
    void solve(int index,vector<int>& current, int sum,vector<int>& nums, vector<vector<int>>& res){
        if(index == nums.size()){
            if(sum==0) res.push_back(current);
            return;
        }
        // pick
        if(sum - nums[index]>=0){
            current.push_back(nums[index]);
            solve(index,current,sum-nums[index],nums,res);
            current.pop_back();
        }
        // not pick
        solve(index+1,current,sum,nums,res);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> current;
        solve(0,current,target,candidates,res);
        return res;
    }
};