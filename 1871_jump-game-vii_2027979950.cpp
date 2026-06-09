class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if (s[n - 1] == '1')
            return false;

        // instead of checking jump from i to j, think ulta
        // can we reach index j from previous indices

        vector<bool> dp(n, false); // dp[i] = is index i reachable?
        dp[0] = 1;                 // 0th index is always reachable

        int count = 0; // "How many reachable indices are in my current window?"

        // window: s[j-maxJump...j-minJump]
        for (int j = 1; j < n; j++) {
            // Add the index that just entered the window
            if (j - minJump >= 0) {
                count += dp[j - minJump];
            }

            // Remove the index that just fell out of the back of the window
            if (j - maxJump - 1 >= 0) {
                count -= dp[j - maxJump - 1];
            }

            // If there is at least one reachable index in our window, and
            // current is '0'
            if (count > 0 && s[j] == '0') {
                dp[j] = true;
            }
        }
        return dp[n - 1];
    }
};