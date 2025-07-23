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
        vector<int> dp(n + 1, 0); // dp for cuts
        // dp for isPali check
        vector<vector<bool>> checkPali(n, vector<bool>(n, -1));

        // here we can also optimise the isPali check - which takes O(N) time
        // each time we can precompute the checkPali[i][j] = isPali(str,i,j) in
        // O(1)

        // s[i...j] --> s[i+1...j-1]
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2)
                        checkPali[i][j] = true;
                    else
                        checkPali[i][j] = checkPali[i + 1][j - 1];
                }
            }
        }

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