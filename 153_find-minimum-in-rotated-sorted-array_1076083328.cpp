class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;

            // cout << lo << " " << mid << " " << hi << " " << prev << " " << next <<"\n";

            if(nums[mid]<=nums[prev] && nums[mid]<=nums[hi]){
                return nums[mid];
            }
            else if(nums[mid]<=nums[hi]){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return -1;
    }
};