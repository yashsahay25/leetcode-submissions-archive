class Solution {
public:
    void solve(string input, vector<string>& output, int open, int close){
        if(open==0 && close==0)
            output.push_back(input);
        if(open!=0){
            string ip1 = input;
            ip1.push_back('(');
            solve(ip1,output,open-1,close);
        }
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
        solve(str,output,open,close);
        return output;
    }
};