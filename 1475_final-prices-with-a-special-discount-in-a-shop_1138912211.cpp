class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> v(n);

        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top() > prices[i])
                s.pop();
            if(s.empty())
                v[i] = 0;
            else
                v[i] = s.top();
            s.push(prices[i]);
        }
        for(int i=0;i<n;i++){
            v[i] = prices[i] - v[i];
        }
        return v;
    }
};