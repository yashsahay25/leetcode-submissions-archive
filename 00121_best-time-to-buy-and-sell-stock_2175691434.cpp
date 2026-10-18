class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int buy = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > buy) {
                maxP = max(maxP, prices[i] - buy);
            } else {
                buy = prices[i];
            }
        }
        return maxP;
    }
};