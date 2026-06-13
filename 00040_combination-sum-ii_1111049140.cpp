class Solution {
public:
    void backtrack(int index, int target,vector<int>& candidates,vector<int> current, vector<vector<int>>& result){
        // base condition
        // since we are using for loop, no need to check if(index == n)
        if(target==0){
            result.push_back(current);
            return;
        }


        // each array element can be taken, so using for loop 
        for(int i=index;i<candidates.size();i++){
            if(target-candidates[i]>=0)
            {
                if (i > index && candidates[i] == candidates[i - 1])  // skip duplicates
                    continue;
                current.push_back(candidates[i]); // take
                // take, so target reduces
                backtrack(i+1,target-candidates[i],candidates,current,result);
                current.pop_back(); // not take
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(),candidates.end());
        backtrack(0,target,candidates,current,result);
        return result;
    }
};