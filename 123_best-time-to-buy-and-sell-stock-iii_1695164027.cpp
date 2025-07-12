class Solution {
public:
    int solveMemoised(int index, int allowedToBuy, vector<int>& prices, 
        vector<vector<vector<int>>>& dp, int count){
        int n=prices.size();
        if(count==0 || index==n) return 0;

        if(dp[index][allowedToBuy][count]!=-1) return dp[index][allowedToBuy][count];

        long profit=0;
        if(allowedToBuy){
            int buyProfit = -prices[index] + solveMemoised(index+1, 0, prices, dp, count);
            int notBuyProfit = 0 + solveMemoised(index+1, 1, prices, dp, count);
            profit = max(buyProfit, notBuyProfit);
        }else{
            int sellProfit = prices[index] + solveMemoised(index+1, 1, prices, dp, count-1);
            int notSellProfit = 0 + solveMemoised(index+1, 0, prices, dp, count);
            profit = max(sellProfit, notSellProfit);
        }
        return dp[index][allowedToBuy][count] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int k=2; // max transactions

        // dp[n][2][k]
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2, vector<int> (k+1,-1)));
        return solveMemoised(0,1,prices,dp,k);
    }
};