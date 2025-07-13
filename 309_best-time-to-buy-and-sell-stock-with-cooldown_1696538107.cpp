class Solution {
public:
    int solve(int index, int canBuy, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        
        // base case
        if(index >= n) return 0;

        if(dp[index][canBuy]!=-1) return dp[index][canBuy];

        // recurrence
        long profit = 0;
        if (canBuy) {
            int buyProfit = -prices[index] + solve(index + 1, 0, prices, dp);
            int notBuyProfit = 0 + solve(index + 1, 1, prices, dp);
            profit = max(buyProfit, notBuyProfit);
        } else {
            int sellProfit = prices[index] + solve(index + 2, 1, prices, dp);
            int notSellProfit = 0 + solve(index + 1, 0, prices, dp);
            profit = max(sellProfit, notSellProfit);
        }
        return dp[index][canBuy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1)); 
        return solve(0, 1, prices, dp); 
    }
};