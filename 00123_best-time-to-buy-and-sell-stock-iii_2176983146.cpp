class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2; // max txns allowed

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        // dp[n+1][2][k+1];

        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        vector<vector<int>> next(2, vector<int>(k + 1, 0));

        // curr = dp[day], next = dp[day+1]
        for (int day = n - 1; day >= 0; day--) {
            for (int allowedToBuy = 0; allowedToBuy < 2; allowedToBuy++) {
                for (int count = 0; count < k; count++) {
                    int profit = 0;
                    if (allowedToBuy) {
                        int buy = -prices[day] + next[0][count];
                        int notBuy = 0 + next[1][count];
                        profit = max(buy, notBuy);
                    } else {
                        int sell = prices[day] + next[1][count + 1];
                        int notSell = 0 + next[0][count];
                        profit = max(sell, notSell);
                    }
                    curr[allowedToBuy][count] = profit;
                }
            }
            next = curr; // shift states
        }

        return next[1][0];
    }
};