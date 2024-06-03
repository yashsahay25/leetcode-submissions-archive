class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res, vector<int> temp,int index){
        if(index==nums.size()){
            res.push_back(temp);
            return;
        }
        // consider not-pick before pick so that
        // we don't need to add first & then remove later

        // not pick
        solve(nums,res,temp,index+1);

        // pick
        temp.push_back(nums[index]);
        solve(nums,res,temp,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(nums,res,temp,0);
        return res;
    }
};