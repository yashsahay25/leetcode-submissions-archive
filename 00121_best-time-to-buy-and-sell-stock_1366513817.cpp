class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0],profit=0,maxP=0;
        for(int i=1;i<prices.size();i++){
            profit=prices[i]-buy;
            if(profit<0){
                profit=0;
                buy=prices[i];
                continue;
            }
            maxP=max(profit,maxP);
        }
        return maxP;
    }
};