class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target)
                return mid;

            // if left part is sorted
            else if (nums[lo] <= nums[mid]) {
                // if target lies in the left sorted part
                if (nums[lo] <= target && target <= nums[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            
            // if right part is sorted
            } else if (nums[mid] <= nums[hi]) {
                // if target lies in the right sorted part
                if (nums[mid] <= target && target <= nums[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        return -1;
    }
};