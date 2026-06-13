class Solution {
public:
    void solve(string current, vector<string>& result, int open, int close){
        // base case
        if(open==0 && close==0)
            result.push_back(current);
        // we can add open bracket until it's count is non-zero
        if(open!=0){
            string str1 = current;
            str1.push_back('(');
            solve(str1,result,open-1,close);
        }
        // we can closed bracket only if it's in excess (not even equal)
        if(close>open){
            string str2 = current;
            str2.push_back(')');
            solve(str2,result,open,close-1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        int open = n, close = n;
        vector<string> result;
        string current="";
        solve(current,result,open,close); // call recursive function
        return result;
    }
};