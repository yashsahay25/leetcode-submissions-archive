class Solution {
public:
    long long calcSum(vector<int>& piles, int k){
        int n=piles.size();
        long long sum=0;
        for(int i=0;i<n;i++)
            sum += ceil(double(piles[i])/k);
        // alternative
        // for (int p : piles)
        //         sum += (p + k - 1) / k;
        
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // k can lie from 1 to arr_max
        int m = *max_element(piles.begin(),piles.end());

        int lo=1,hi=m;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            long long sum = calcSum(piles,mid);
            if(sum<=h)
                hi = mid-1;
            else
                lo = mid+1;
        }
        return lo;
    }
};