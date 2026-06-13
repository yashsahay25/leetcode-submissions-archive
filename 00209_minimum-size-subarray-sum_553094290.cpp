class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,sum=0,len=INT_MAX;
        while(j<n)
        {
            sum+=nums[j];
            if(sum>=k)
            {
                while(sum>=k)
                {
                    len = min(len,j-i+1);
                    sum-=nums[i];
                    i++;
                }
            }
            j++;
        }
        return len==INT_MAX?0:len;
    }
};