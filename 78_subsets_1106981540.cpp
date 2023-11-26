class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>& res,vector<int> out,int index)
    {
        // base case
        if(index==nums.size()){
            res.push_back(out);
            return;
        }
        // not take
        solve(nums,res,out,index+1); // directly call for next index

        // take
        out.push_back(nums[index]); // include
        solve(nums,res,out,index+1); // call for next index
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        solve(nums,res,out,0); // call recursive function
        return res;
    }
};