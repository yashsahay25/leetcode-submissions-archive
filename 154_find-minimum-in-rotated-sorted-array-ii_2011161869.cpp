class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1;

        while(lo<n-1 && nums[lo]==nums[lo+1]) lo++;
        while(hi>1 && nums[hi]==nums[hi-1]) hi--;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[lo] <= nums[mid] && nums[mid] <= nums[hi])
                return nums[lo];
            else if (nums[lo] <= nums[mid] && nums[mid] >= nums[hi])
                lo = mid + 1;
            else if (nums[lo] >= nums[mid] && nums[mid] <= nums[hi])
                hi = mid;
        }
        return nums[lo];
    }
};