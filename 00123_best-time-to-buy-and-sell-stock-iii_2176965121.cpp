class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2; // max txns allowed

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        // dp[n+1][2][k+1];

        for (int day = n - 1; day >= 0; day--) {
            for (int allowedToBuy = 0; allowedToBuy < 2; allowedToBuy++) {
                for (int count = 0; count < k; count++) {
                    int profit = 0;
                    if (allowedToBuy) {
                        int buy = -prices[day] + dp[day + 1][0][count];
                        int notBuy = 0 + dp[day + 1][1][count];
                        profit = max(buy, notBuy);
                    } else {
                        int sell = prices[day] + dp[day + 1][1][count + 1];
                        int notSell = 0 + dp[day + 1][0][count];
                        profit = max(sell, notSell);
                    }
                    dp[day][allowedToBuy][count] = profit;
                }
            }
        }

        return dp[0][1][0];
    }
};