class Solution {
public:
    int solveTabulation(vector<int>& prices, vector<vector<vector<int>>>& dp, int count){
            int n=prices.size();
            // base case - already covered in dp initialisation

            // for loop in terms of state variables
            for(int index=n-1;index>=0;index--) {
                for(int buy=0;buy<=1;buy++) {
                    for(int k=1;k<=count;k++) { // k==0 covered in base case during dp initialisation itself
                        long profit=0;
                        
                        if(buy) {
                            int buyProfit = -prices[index] + dp[index+1][0][k];
                            int notBuyProfit = 0 + dp[index+1][1][k];
                            profit = max(buyProfit, notBuyProfit);
                        } else {
                            int sellProfit = prices[index] + dp[index+1][1][k-1];
                            int notSellProfit = 0 + dp[index+1][0][k];
                            profit = max(sellProfit, notSellProfit);
                        }
                        dp[index][buy][k] = profit;
                    }
                }
            }
            return dp[0][1][count];
        }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int k=2; // max transactions

        // dp[n][2][k]
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2, vector<int> (k+1,0)));
        return solveTabulation(prices,dp,k);
    }
};