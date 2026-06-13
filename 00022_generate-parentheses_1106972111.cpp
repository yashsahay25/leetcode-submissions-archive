class Solution {
public:
    void solve(string input, vector<string>& output, int open, int close){
        // base case
        if(open==0 && close==0)
            output.push_back(input);
        // we can add open bracket until it's count is non-zero
        if(open!=0){
            string ip1 = input;
            ip1.push_back('(');
            solve(ip1,output,open-1,close);
        }
        // we can closed bracket only if it's in excess (not even equal)
        if(close>open){
            string ip2 = input;
            ip2.push_back(')');
            solve(ip2,output,open,close-1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        vector<string> output;
        string str="";
        solve(str,output,open,close); // call recursive function
        return output;
    }
};