class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            // Ensure mid is even, so we can compare with mid + 1
            if (mid % 2 == 1) {
                mid--;
            }

            // If nums[mid] == nums[mid + 1], single element is in right half
            if (nums[mid] == nums[mid + 1]) {
                lo = mid + 2;
            } else { // Otherwise, single element is in the left half
                hi = mid;
            }
        }

        // 'lo' will eventually point to the single element
        return nums[lo];
    }
};