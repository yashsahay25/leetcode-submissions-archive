class Solution {
public:
    int numTrees(int n) {
        //answer is Catalan numbers
        //for a node i, left has (i-1) and right has (i+1)options
        
        vector<int> dp(n+1, 0);
        dp[0]=dp[1]=1;
        //sol[i] = (sol[0]*sol[i-1] + sol[1]*sol[i-2] +.......+sol[i-1]*sol[0])
        for(int i=2; i<=n; i++){
            for(int j=0; j<i; j++)
                dp[i]+= dp[j]*dp[i-1-j];
        }
        return dp[n];
    }
};