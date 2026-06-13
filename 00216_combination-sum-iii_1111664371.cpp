class Solution {
public:
    void backtrack(int index,int k,int target,vector<int>& nums,vector<int>& current,vector<vector<int>>& result){
        // base case
        if(current.size()==k){
            if(target==0){
                result.push_back(current);
            }
            return;
        }
        // main logic
        for(int i=index;i<nums.size();i++){
            if(target-nums[i]>=0){
                current.push_back(nums[i]);
                backtrack(i+1,k,target-nums[i],nums,current,result);
                current.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> current;
        backtrack(0,k,n,nums,current,result);
        return result;
    }
};