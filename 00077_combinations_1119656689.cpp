class Solution {
public:
    void backtrack(int start,vector<int>& current,int n,int k,vector<vector<int>>& result){
        if(current.size()==k){
            result.push_back(current);
            return;
        }
        for(int i=start;i<=n;i++){
            current.push_back(i);
            backtrack(i+1,current,n,k,result);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1,current,n,k,result);
        return result;
    }
};