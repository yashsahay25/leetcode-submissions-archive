class Solution {
public:
    int calcProfit(int day, bool allowedToBuy, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        if (day == n)
            return 0;
        
        if(dp[day][allowedToBuy]!=-1) 
            return dp[day][allowedToBuy];

        int profit = 0;
        if (allowedToBuy) {
            int buyProfit = -prices[day] + calcProfit(day + 1, false, prices, dp);
            int notBuyProfit = 0 + calcProfit(day + 1, true, prices, dp);
            profit = max(buyProfit, notBuyProfit);
        } else {
            // not allowed to buy, so can sell that day or not sell
            int sellProfit = prices[day] + calcProfit(day + 1, true, prices, dp);
            int notSellProfit = 0 + calcProfit(day + 1, false, prices, dp);
            profit = max(sellProfit, notSellProfit);
        }
        return dp[day][allowedToBuy] = profit;
    }
    int maxProfit(vector<int>& prices) { 
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return calcProfit(0, true, prices, dp); 
    }
};