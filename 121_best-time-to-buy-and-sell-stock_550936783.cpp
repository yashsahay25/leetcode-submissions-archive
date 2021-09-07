class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int p_diff=0;   //to store maximum possible price difference
        for(int i=0;i<prices.size();i++)
        {
            minPrice=min(prices[i],minPrice);
            if(prices[i]>minPrice)
            {
                p_diff=max(p_diff,prices[i]-minPrice);
            }
        }
        return p_diff;
    }
};










































