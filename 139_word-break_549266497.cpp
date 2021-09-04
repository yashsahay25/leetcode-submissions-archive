class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto& w:wordDict)
            dict.insert(w);
        
        int n = s.length();
        vector<bool> dp(n+1,false);
        dp[0]=1;    //empty string possible with any dictionary

        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<i;j++)   //to check every prefix
            {
                if(dp[j])
                {
                    string word2check = s.substr(j,i-j);
                    //auto it = find(wordDict.begin(), wordDict.end(), word2check);
                    if(dict.find(word2check)!=dict.end()) //prefix found
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
        //return dp.back();
    }
};