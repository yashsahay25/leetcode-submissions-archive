class Solution {
public:
    int lcsSpaceOptimised(string s1, string s2, int m, int n, vector<int>& prev,
                          vector<int>& curr) {
        // base case - i==0 || j==0 already handled in initialisation
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[n];
    }
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();

        // Space Optimised
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        int l = lcsSpaceOptimised(word1, word2, m, n, prev, curr);
        return m + n - 2 * l;
    }
};