class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0, buy = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - buy;
            if (profit < 0) {
                profit = 0;
                buy = prices[i];
                continue;
            }
            maxP = max(maxP, profit);
        }
        return maxP;
    }
};