class Solution {
public:
    bool isBeautiful(string& s, int start, int end) {
        // leading zero
        if (s[start] == '0')
            return false;

        // convert to decimal value
        long long num = 0;
        for (int i = start; i <= end; ++i) {
            num = num * 2 + (s[i] - '0');
        }

        // check for power of 5
        if (num <= 0)
            return false;
        while (num % 5 == 0) {
            num /= 5;
        }
        return num == 1;
    }
    int solveTabulation(string s) {
        int n = s.length();
        
        vector<int> dp(n + 1, INT_MAX - 1);
        dp[n] = 0;
        
        for (int index = n - 1; index >= 0; index--) {
            int minCount = INT_MAX - 1;
            for (int j = index; j < n; j++) {
                if (isBeautiful(s, index, j)) {
                    int count = 1 + dp[j + 1];
                    minCount = min(count, minCount);
                }
            }
            dp[index] = minCount;
        }
        return dp[0];
    }
    int minimumBeautifulSubstrings(string s) {
        int n = s.length();
        // vector<int> dp(n, -1);
        // int ans = solve(0, s, dp);
        // return ans == INT_MAX - 1 ? -1 : ans;
        int ans = solveTabulation(s);
        return ans == INT_MAX - 1 ? -1 : ans;
    }
};