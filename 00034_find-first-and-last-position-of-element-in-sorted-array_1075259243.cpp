class Solution {
public:
    int bs1(vector<int>& nums, int target){
        int lo=0,hi=nums.size()-1;
        int res1=-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]==target){
                res1 = mid;
                hi=mid-1;
            }
            else if(nums[mid]<target)
                lo=mid+1;
            else
                hi=mid-1;
        }
        return res1;
    }
    int bs2(vector<int>& nums, int target){
        int lo=0,hi=nums.size()-1;
        int res2=-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]==target){
                res2 = mid;
                lo=mid+1;
            }
            else if(nums[mid]<target)
                lo=mid+1;
            else
                hi=mid-1;
        }
        return res2;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int res1,res2;
        res1 = bs1(nums,target);
        res2 = bs2(nums,target);
        return {res1,res2};
    }
};