class Solution {
public:
    bool possible(vector<int>& v,int m,int k,int mid){
        int n=v.size();
        int adjacent=0,bq=0;
        for(int i=0;i<n;i++){
            if(v[i]<=mid)
                adjacent++;
            else {
                bq += adjacent/k;
                adjacent = 0;
            }
        }
        bq += adjacent/k; // covering last set of adjacents
        return (bq >= m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        // base case
        long long val = m * 1ll * k * 1ll;
        if(n<val) return -1;

        int lo = *min_element(bloomDay.begin(),bloomDay.end());
        int hi = *max_element(bloomDay.begin(),bloomDay.end());
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;

            if(possible(bloomDay,m,k,mid))
                hi=mid-1;
            else
                lo=mid+1;
        }
        return lo;
    }
};