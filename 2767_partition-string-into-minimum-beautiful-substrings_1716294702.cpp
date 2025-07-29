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

    int solve(int index, string& s, vector<int>& dp) {
        int n = s.length();
        if (index == n)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int minCount = INT_MAX - 1;
        for (int j = index; j < n; j++) {
            // s[index...j] and recurse for rest part (j+1...n)
            if (isBeautiful(s, index, j)) {
                int count = 1 + solve(j + 1, s, dp);
                minCount = min(count, minCount);
            }
        }
        return dp[index] = minCount;
    }

    int minimumBeautifulSubstrings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        int ans = solve(0, s, dp);
        return ans == INT_MAX - 1 ? -1 : ans;
    }
};