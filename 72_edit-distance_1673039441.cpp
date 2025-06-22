class Solution {
public:
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        int m = s1.length();
        int n = s2.length();

        // base case
        for (int i = 0; i <= m; i++)    dp[i][0] = i;
        for (int j = 0; j <= n; j++)    dp[0][j] = j;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // equal
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } // not equal
                else {
                    int ins = dp[i][j - 1];
                    int del = dp[i - 1][j];
                    int rep = dp[i - 1][j - 1];
                    dp[i][j] = 1 + min({ins, del, rep});
                }
            }
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        return solve(word1, word2, m, n, dp);
    }
};