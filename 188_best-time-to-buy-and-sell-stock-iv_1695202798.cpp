class Solution {
public:
    int solveTabulation(vector<int>& prices, int count) {
        vector<vector<int>> ahead(2, vector<int>(count + 1, 0));
        vector<vector<int>> curr(2, vector<int>(count + 1, 0));
        int n = prices.size();

        // for loop in terms of state variables
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int k = 1; k <= count; k++) {
                    long profit = 0;

                    if (buy) {
                        int buyProfit = -prices[index] + ahead[0][k];
                        int notBuyProfit = 0 + ahead[1][k];
                        profit = max(buyProfit, notBuyProfit);
                    } else {
                        int sellProfit = prices[index] + ahead[1][k - 1];
                        int notSellProfit = 0 + ahead[0][k];
                        profit = max(sellProfit, notSellProfit);
                    }
                    curr[buy][k] = profit;
                }
            }
            ahead = curr;
        }
        return ahead[1][count];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return solveTabulation(prices, k);
    }
};