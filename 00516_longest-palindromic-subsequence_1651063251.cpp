class Solution {
public:
    int lcsTabulated(string s1, string s2, int n, vector<vector<int>>& dp) {
        // base case - i==0 || j==0 already handled in initialisation
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }

    int lcsSpaceOptimised(string s1, string s2, int n, vector<int>& prev, vector<int>& curr) {
        // base case - i==0 || j==0 already handled in initialisation
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        return prev[n];
    }

    int longestPalindromeSubseq(string s) {
        string r=s;
        reverse(s.begin(),s.end());
        int n=s.length();

        // Tabulated
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // return lcsTabulated(s, r, n, dp);

        // Space Optimised
        vector<int> prev(n+1, 0), curr(n+1, 0);
        return lcsSpaceOptimised(s, r, n, prev, curr);

    }
};