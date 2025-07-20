class Solution {
public:
    int solve(vector<int>& cuts) {
        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int>(c, 0));
        for (int i = c - 1; i >= 0; i--) {
            for (int j = i + 2; j < c; j++) {

                int minCost = INT_MAX;
                for (int k = i + 1; k <= j - 1; k++) {
                    int cost = cuts[j] - cuts[i] + dp[i][k] + dp[k][j];
                    minCost = min(cost, minCost);
                }
                dp[i][j] = minCost;
            }
        }
        return dp[0][c - 1];
    }
    int minCost(int n, vector<int>& cuts) {
        // Add the two ends of the stick as virtual cuts
        cuts.push_back(0);
        cuts.push_back(n);

        // sort to ensure that cuts of each partition are in order
        sort(cuts.begin(), cuts.end());
        return solve(cuts);
    }
};