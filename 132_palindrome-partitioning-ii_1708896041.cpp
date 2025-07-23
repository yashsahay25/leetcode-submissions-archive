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
    int solve(int index, string& s, vector<int>& dp) {
        int n = s.length();

        // base case
        if (index == n)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int minCuts = INT_MAX;
        // we are putting partition using k
        // s[0...k....n-1]
        for (int k = index; k < n; k++) {
            // s[0...k] will be our partition to check
            if (isPali(index, k, s)) {
                int cuts = (k == n - 1) ? 0 : 1 + solve(k + 1, s, dp);
                minCuts = min(cuts, minCuts);
            }
        }
        return dp[index] = minCuts;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return solve(0, s, dp);
    }
};