class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (mid > 0 && mid < n - 1) {
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                    return mid;
                }
                // move towards more promising side
                // ie. if left element is larger, it can be peak, so move left
                else if (nums[mid - 1] > nums[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else if (mid == 0) {
                if (nums[mid] > nums[mid + 1]) {
                    return mid;
                } else {
                    lo = mid + 1; // Move right if not a peak
                }
            } else if (mid == n - 1) {
                if (nums[mid] > nums[mid - 1]) {
                    return mid;
                } else {
                    hi = mid - 1; // Move left if not a peak
                }
            }
        }
        return -1;
    }
};