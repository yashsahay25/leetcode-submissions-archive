class Solution {
public:
    void backtrack(int index, int target,vector<int>& candidates,vector<int>& current, vector<vector<int>>& result){
        // base condition
        if(index==candidates.size()){
            if(target==0)
                result.push_back(current);
            return;
        }
            // take
            if(target-candidates[index]>=0){ // check if condition holds
                current.push_back(candidates[index]);
                // take, so target reduces
                backtrack(index,target-candidates[index],candidates,current,result);
                current.pop_back(); // undo take
            }
            
            // not take, so target remains same
            backtrack(index+1,target,candidates,current,result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0,target,candidates,current,result);
        return result;
    }
};