class Solution {
public:
    int solve(string& s1, string& s2, vector<int>& prev, vector<int>& curr) {
        int n = s1.length(), m = s2.length();

        // base case
        for (int j = 0; j <= m; j++)    prev[j] = j;

        for (int i = 1; i <= n; i++) {
            curr[0] = i; // base case
            for (int j = 1; j <= m; j++) {
                // equal
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = prev[j - 1];
                } // not equal
                else {
                    int ins = curr[j - 1];
                    int del = prev[j];
                    int rep = prev[j - 1];
                    curr[j] = 1 + min({ins, del, rep});
                }
            }
            prev = curr;
        }
        return prev[m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        return solve(word1, word2, prev, curr);
    }
};