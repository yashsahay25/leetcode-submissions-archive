class Solution {
public:
    bool isValid(vector<int>& nums,int n,int mid,int m)
    {
        int count=1,sum=0;
        for(int i=0;i<n;i++)
        {
            sum+= nums[i];
            if(sum>mid)
            {
                count++;
                sum=nums[i];
            }
            if(count>m) return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        //sort(nums.begin(),nums.end());
        int lo=-1,hi=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            lo = max(lo,nums[i]);
            hi += nums[i];
        }
        int res=-1;
        while(lo<=hi)
        {
            int mid = lo+(hi-lo)/2;
            if(isValid(nums,n,mid,m))
            {
                res=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        return res;
    }
};