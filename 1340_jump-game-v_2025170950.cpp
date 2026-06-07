class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();

        // dp[i] = number of indices you can visit from i
        vector<int> dp(n + 1, 1); // initially, every index can be visited once

        vector<pair<int, int>> nodes;
        for (int i = 0; i < n; i++) {
            nodes.push_back({arr[i], i});
        }
        // sorting required so that we visit lesser value elements before
        // as per ques requirement, we cannot visited a higher value later
        sort(nodes.begin(), nodes.end());

        for (auto& [val, i] : nodes) {
            // left
            for (int j = i - 1; j >= max(0, i - d); j--) {
                if (arr[j] >= arr[i])
                    break;
                dp[i] = max(dp[i], 1 + dp[j]);
            }

            // right
            for (int j = i + 1; j <= min(n - 1, i + d); j++) {
                if (arr[j] >= arr[i])
                    break;
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        // final ans will be max of dp[i]
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};