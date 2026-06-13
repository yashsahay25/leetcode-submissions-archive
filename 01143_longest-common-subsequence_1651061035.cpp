class Solution {
public:
    int lcsRecursive(string s1, string s2, int i, int j) {
        if (i == 0 || j == 0)   return 0;
        
        if (s1[i - 1] == s2[j - 1])
            return 1 + lcsRecursive(s1, s2, i - 1, j - 1);
        return max(lcsRecursive(s1, s2, i, j - 1), lcsRecursive(s1, s2, i - 1, j));
    }

    int lcsMemoised(string s1, string s2, int i, int j,
                    vector<vector<int>>& dp) {
        if (i == 0 || j == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i - 1] == s2[j - 1])
            return dp[i][j] = 1 + lcsMemoised(s1, s2, i - 1, j - 1, dp);

        return dp[i][j] = max(lcsMemoised(s1, s2, i, j - 1, dp),
                            lcsMemoised(s1, s2, i - 1, j, dp));
    }

    int lcsTabulated(string s1, string s2, int m, int n, vector<vector<int>>& dp) {
        // base case - i==0 || j==0 already handled in initialisation
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }

    int lcsSpaceOptimised(string s1, string s2, int m, int n, vector<int>& prev, vector<int>& curr) {
        // base case - i==0 || j==0 already handled in initialisation
        for(int i=1;i<=m;i++){
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

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        // Recursive
        // return lcsRecursive(text1, text2, m, n);

        // Memoized
        // vector<vector<int>> dp1(m+1, vector<int>(n+1, -1));
        // return lcsMemoised(text1, text2, m, n, dp1);

        // Tabulated
        // vector<vector<int>> dp2(m+1, vector<int>(n+1, 0));
        // return lcsTabulated(text1, text2, m, n, dp2);

        // Space Optimised
        vector<int> prev(n+1, 0), curr(n+1, 0);
        return lcsSpaceOptimised(text1, text2, m, n, prev, curr);
    }
};