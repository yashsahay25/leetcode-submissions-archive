class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            // Note: No explicit need to check if mid is smaller than eiter
            // neighbors

            // The right part is unsorted, eliminate the left part
            if (nums[mid] > nums[hi])
                lo = mid + 1;
            else
                hi = mid; // eliminate the right half, excluding mid
        }
        return nums[lo];
    }
};