class Solution {
private:
    void solve(int start,int sum,vector<int>& current,int k,vector<vector<int>>& res){
        if(current.size()==k){
            if(sum==0) res.push_back(current);
            return;
        }
        if(start>9) return;

        // pick
        if(sum-start>=0){
            current.push_back(start);
            solve(start+1,sum-start,current,k,res);
            current.pop_back();
        }
        // not pick
        solve(start+1,sum,current,k,res);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> current;
        solve(1,n,current,k,res);
        return res;
    }
};