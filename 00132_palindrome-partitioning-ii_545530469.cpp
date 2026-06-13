class Solution {
public:
    int dp[2001][2001];
    
    /*bool isPalindrome(string s,int i,int j)
    {
        if(i==j)    return true;
        if(i>j) return false;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
        }
        return true;
    }*/
    int isPalindrome(string s)
    {
        int n=s.size();
        for(int i=0;i<=n/2;i++)
            if(s[i]!=s[n-1-i])
                return 0;
        return 1;
    }
    int solve(string s,int i,int j)
    {
        if(i>=j)    return 0;
        
        //if(isPalindrome(s,i,j))
        if(isPalindrome(s.substr(i,j-i+1)))
            return dp[i][j]=0;
        if(dp[i][j]!=-1)    return dp[i][j];
        
        
        int mn=INT_MAX;
        for(int k=i;k<j;k++)
        {
            //if(isPalindrome(s,i,k))
            if(isPalindrome(s.substr(i,k-i+1)))
            {
                int r;
                if(dp[k+1][j]!=-1)
                    r=dp[k+1][j];
                else 
                    r=solve(s,k+1,j);
                int temp = 1+r;
                mn = min(mn, temp);                
            }
        }
        return dp[i][j]=mn;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.length()-1);
    }
};