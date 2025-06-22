class Solution {
public:
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        // base case
        if (i < 0)  return j + 1;
        if (j < 0)  return i + 1;

        if (dp[i][j] != -1) return dp[i][j];

        // recurrence
        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i - 1, j - 1, dp);
        } else {
            int ins = solve(s1, s2, i, j - 1, dp);
            int del = solve(s1, s2, i - 1, j, dp);
            int rep = solve(s1, s2, i - 1, j - 1, dp);
            return dp[i][j] = 1 + min({ins, del, rep});
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(word1, word2, m - 1, n - 1, dp);
    }
};