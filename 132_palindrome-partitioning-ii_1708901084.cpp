class Solution {
public:
    bool isPali(int l, int r, string& s) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);

        for (int index = n - 1; index >= 0; index--) {
            int minCuts = INT_MAX;
            for (int k = index; k < n; k++) {
                if (isPali(index, k, s)) {
                    int cuts = (k == n - 1) ? 0 : 1 + dp[k + 1];
                    minCuts = min(cuts, minCuts);
                }
            }
            dp[index] = minCuts;
        }
        return dp[0];
    }
};