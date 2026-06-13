class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> left(n),right(n);
        
        int leftmin = prices[0];
        for(int i=1;i<n;i++)
        {
            left[i] = max(left[i-1],prices[i]-leftmin);
            leftmin = min(leftmin,prices[i]);
        }
        
        int rightmax = prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i] = max(right[i+1],rightmax-prices[i]);
            rightmax = max(rightmax,prices[i]);
        }
        int profit=right[0];
        for(int i=1;i<n;i++)
            profit = max(profit,left[i]+right[i]);
        return profit;
    }
};