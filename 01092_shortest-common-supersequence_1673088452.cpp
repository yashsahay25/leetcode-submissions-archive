class Solution {
public:
    void lcsTabulated(string& s1, string& s2, vector<vector<int>>& dp) {
        int n = s1.length(), m = s2.length();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        // return dp[n][m];
    }
    string printSCS(string& s1, string& s2, vector<vector<int>>& dp) {
        int n = s1.length(), m = s2.length();
        int i = n, j = m;
        string res = "";

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                res.push_back(s1[i - 1]);
                i--, j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) { // moving up
                    res.push_back(s1[i - 1]);
                    i--;
                } else {
                    res.push_back(s2[j - 1]);
                    j--;
                }
            }
        }
        while (i > 0) { // if s1 is left
            res.push_back(s1[i - 1]);
            i--;
        }
        while (j > 0) { // if s1 is left
            res.push_back(s2[j - 1]);
            j--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // int scsLength = n + m - 2 * lcsTabulated(s1, s2);
        lcsTabulated(str1, str2, dp);

        // print SCS
        return printSCS(str1, str2, dp);
    }
};