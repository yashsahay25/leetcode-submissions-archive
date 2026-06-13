class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            int buyPrice = prices[0];	// buy on first day with that price
            int profit = 0;	// initial max profit is 0

            for (int i = 1; i < prices.size(); i++)
            {
               	// 2 scenarios - current price (prices[i]) is > or < than buyPrice
                if (prices[i] < buyPrice)
                {
                    buyPrice = prices[i];	// if current price is less, update buyPrice
                }
                else
                {
                    int currentProfit = prices[i] - buyPrice;	// calculate current profit
                    profit = max(currentProfit, profit);	// update maxProfit
                }
            }
            return profit;
        }
};