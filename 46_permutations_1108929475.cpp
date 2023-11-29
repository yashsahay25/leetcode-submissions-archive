class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& nums,int index){
        if(index >= nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            backtrack(result,nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        // instead of passing current array, we will directly use nums array
        backtrack(result,nums,0); // call swap based recursion
        return result;
    }
};