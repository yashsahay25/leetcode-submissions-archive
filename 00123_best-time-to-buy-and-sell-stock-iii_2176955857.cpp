class Solution {
public:
    int calc(int day, bool allowedToBuy, int count, int k, vector<int>& prices,
             vector<vector<vector<int>>>& dp) {
        if (day == prices.size() || count >= k)
            return 0;

        if (dp[day][allowedToBuy][count] != -1)
            return dp[day][allowedToBuy][count];

        int profit = 0;
        if (allowedToBuy) {
            int buy = -prices[day] + calc(day + 1, false, count, k, prices, dp);
            int notBuy = 0 + calc(day + 1, true, count, k, prices, dp);
            profit = max(buy, notBuy);
        } else {
            int sell =
                prices[day] + calc(day + 1, true, count + 1, k, prices, dp);
            int notSell = 0 + calc(day + 1, false, count, k, prices, dp);
            profit = max(sell, notSell);
        }
        return dp[day][allowedToBuy][count] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2; // max txns allowed

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k, -1)));
        // dp[n][2][k];

        return calc(0, true, 0, k, prices, dp);
    }
};