class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& nums,int index){
        if(index >= nums.size()){
            result.push_back(nums);
            return;
        }
        // use set to track if the element has already been picked
        // so that we can avoid duplicate calls
        unordered_set<int> s;
        for(int i=index;i<nums.size();i++){
            if(s.find(nums[i]) != s.end()) continue; // skip duplicates at i
            s.insert(nums[i]);  // mark as used in set
            swap(nums[i],nums[index]);
            backtrack(result,nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        // instead of passing current array, we will directly use nums array
        backtrack(result,nums,0); // call swap based recursion
        return result;
    }
};