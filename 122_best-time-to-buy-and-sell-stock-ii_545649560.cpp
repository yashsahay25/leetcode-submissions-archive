class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*we buy whenever there is a valley & sell at peak
        instead of checking every time for a peak or valley,
        we can simply check if today's price is more than yesterday's,
        so we include it in our profit.
        */
        int profit=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1])
                profit+=(prices[i]-prices[i-1]);
        }
        return profit;
    }
};