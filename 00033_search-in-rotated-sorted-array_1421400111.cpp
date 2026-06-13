class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int r, int target) {
        int lo = l, hi = r;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return -1;
    }
    int findMinIndex(vector<int>& nums) {
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
        return lo;
    }
    int search(vector<int>& nums, int target) {
        int p = findMinIndex(nums);
        int left = binarySearch(nums, 0, p - 1, target);
        if (left != -1)
            return left;
        int right = binarySearch(nums, p, nums.size() - 1, target);
        return right;
    }
};