class Solution {
public:
    bool isPalindrome(string str){
        int l=0,r=str.length()-1;
        while(l<r){
            if(str[l]!=str[r]) return false;
            l++,r--;
        }
        return true;
    }
    void solve(int index,string s,vector<string>& current,vector<vector<string>>& res){
        if(index==s.length()){
            res.push_back(current);
            return;
        }
        // explore all choices
        for(int i=index;i<s.length();i++){
            string s1 = s.substr(index,i-index+1); // substring = s[index....i]
            if(isPalindrome(s1)){
                current.push_back(s1);      // pick
                solve(i+1,s,current,res);   //backtrack for next
                current.pop_back();         // not pick
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> current;
        solve(0,s,current,res);
        return res;
    }
};