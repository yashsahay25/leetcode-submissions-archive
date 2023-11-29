class Solution {
public:
    void backtrack(vector<int>& nums,vector<vector<int>>& res,vector<int> current,int index) 
    {
        res.push_back(current); // add current to result
        for (int i = index; i < nums.size(); i++) { 
            current.push_back(nums[i]);     // Take
            backtrack(nums, res,current, i+1);    // backtrack
            current.pop_back();             // Not Take
	}
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current; 
        backtrack(nums,res,current,0); // call recursive function
        return res;
    }
};