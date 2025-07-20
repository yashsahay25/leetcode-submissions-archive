class Solution {
public:
    int solve(int l, int r, vector<int>& cuts, vector<vector<int>>& dp) {
        // base case - segment length should atleast be 2
        if (r - l < 2) return 0;
        
        if (dp[l][r] != -1) return dp[l][r];

        int minCost = INT_MAX;

        // Try making a cut at every position between l and r
        for (int k = l + 1; k <= r - 1; k++) {
            int currentCost = cuts[r] - cuts[l];
            int leftSubproblemCost = solve(l, k, cuts, dp);
            int rightSubproblemCost = solve(k, r, cuts, dp);
            int cost = currentCost + leftSubproblemCost + rightSubproblemCost;
            minCost = min(cost, minCost);
        }
        return dp[l][r] = minCost;
    }
    int minCost(int n, vector<int>& cuts) {
        // Add the two ends of the stick as virtual cuts
        cuts.push_back(0);
        cuts.push_back(n);

        // sort to ensure that cuts of each partition are in order
        sort(cuts.begin(), cuts.end());

        int c = cuts.size();
        vector<vector<int>> dp(c,vector<int> (c,-1));
        return solve(0, c - 1, cuts, dp);
    }
};