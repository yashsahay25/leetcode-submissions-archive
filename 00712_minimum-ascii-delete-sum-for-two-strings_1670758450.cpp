class Solution {
public:
    int asciiSum(string s) {
        int sum = 0;
        for (char c : s)
            sum += int(c);
        return sum;
    }
    int lcsTabulated(string s1, string s2, int m, int n,
                     vector<vector<int>>& dp) {
        // base case - i==0 || j==0 already handled in initialisation
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = int(s1[i - 1]) + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
    int minimumDeleteSum(string s1, string s2) {
        // (sum of all chars in A + sum of all chars in B) - 2 *
        // max_ASCII_sum_common_subsequence MASCS(s1, s2)
        // combines LCS concept + max_ASCII_sum in a dp

        // modify the dp table
        // dp[i][j] = max ASCII sum common subsequence b/w s1[0...i-1] and
        // s2[0...j-1] at last, we return dp[n-1][m-1]

        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // Tabulated
        int maxAsciiSum = lcsTabulated(s1, s2, m, n, dp);
        return asciiSum(s1) + asciiSum(s2) - 2 * maxAsciiSum;
    }
};