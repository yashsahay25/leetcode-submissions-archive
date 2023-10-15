class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = l+(r-l)/2;// we use this to avoid integer overflow problem
            
            if (nums[mid] < nums[r])
                r = mid; // The right part is sorted, search in the left part
            else
                l = mid + 1; // The left part is sorted, search in the right part
        }
        return nums[l];
    }
};