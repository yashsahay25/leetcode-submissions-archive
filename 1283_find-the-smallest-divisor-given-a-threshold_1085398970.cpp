class Solution {
public:
    bool findSum(vector<int>& v,int t,int divisor){
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum += ceil(v[i]*1.0/divisor);
        }
        return (sum <= t);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = *max_element(nums.begin(),nums.end());
        int mid;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            if(findSum(nums,threshold,mid))
                hi=mid-1;
            else
                lo=mid+1;
        }
        return lo;
    }
};