class Solution {
public:
    static bool comp(const string& a, const string& b) {
        return a.length() < b.length();
    }
    bool isPredecessor(const string& shorter, const string& longer) {
        if (longer.size() - shorter.size() != 1) return false;

        int i = 0, j = 0;
        // Allow at most one character mismatch (extra character in longer)
        while (i < longer.size()) {
            if (j < shorter.size() && longer[i] == shorter[j]) {
                i++;
                j++;
            } else {
                // Try skipping one character from longer
                i++;
            }
        }
        // If we matched all characters in shorter, it’s a valid predecessor
        return j == shorter.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size(), maxLen = 1;
        vector<int> dp(n, 1);

        // sort input array by length
        sort(words.begin(), words.end(), comp);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPredecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};