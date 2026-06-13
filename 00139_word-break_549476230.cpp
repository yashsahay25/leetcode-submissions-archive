class Solution {
public:
    int dp[301];
    int solve(int i,string s,set<string>& dict)
    {
        if(i==s.size()) //if we reach end of string return true (last stage of backtracking)
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        
        string temp;    //to store substring from i onwards
        
        //one-by-one break the word
        //Example : leetcode -> l/eetcode le/etcode lee/code ... 
        for(int j=i;j<s.size();j++)
        {
            temp+=s[j]; //susbtr can be used as well
            if(dict.find(temp)!=dict.end()) //if 1st part is found in dict, then only solve for rest
                if(solve(j+1,s,dict))
                    return dp[i]=1;
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        if(n==0)    return true;    //it is possible to create empty string
        
        memset(dp,-1,sizeof dp);
        
        //vector = O(n), set = O(log n), unordered set = O(1)avg O(n) worst 
        set<string> dict; //set to store dict words for better TC than vector
        for(auto &w:wordDict)
            dict.insert(w); 
        
        return solve(0,s,dict);
    }
};