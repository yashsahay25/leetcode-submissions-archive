class Solution {
public:
    void backtrack(int k,int target,int start,vector<int>& current,vector<vector<int>>& result){
        // base case
        if(k==0 && target==0){
            result.push_back(current);
            return;
        }
        // main logic
        for(int i=start;i<=9;i++){
            if(target-i>=0){
                current.push_back(i);
                // instead of passing start+1, we pass i+1
                // to avoid duplicates
                backtrack(k-1,target-i,i+1,current,result);
                current.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        // pass start=1 instead of index=0 --> does same thing
        backtrack(k,n,1,current,result);
        return result;
    }
};