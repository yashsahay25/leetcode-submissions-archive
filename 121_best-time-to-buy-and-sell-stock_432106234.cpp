class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int p=0;
        for(int i=0;i<prices.size();i++){
            minPrice=min(prices[i],minPrice);
            if(prices[i]>minPrice){
                p=max(p,prices[i]-minPrice);
            }
        }
        return p;
    }
};