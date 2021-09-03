class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        //base-case
        if(s=="")
            return 1;   //there is 1 way to decode an empty string
        vector<int> dp(n+1,0);
        dp[0]=1;
        if(s[0]!='0')   //starting should not be zero
            dp[1]=1;
        
        for(int i=2;i<=n;i++)//go upto length n
        {
            //2 options -> take the prev individually or club prev 2 together
            int op1 = (s[i-1]-'0');
            int op2 = (s[i-2]-'0')*10 + (s[i-1]-'0');
            
            //now check validity
            if(op1>=1)
                dp[i] += dp[i-1];
            if(op2>=10 and op2<=26)
                dp[i] += dp[i-2];
        }
        return dp[n];
    }
};