class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Compare the middle element with its neighbors
            if (nums[mid] > nums[mid + 1]) {
                // The peak might be on the left side of the array
                right = mid;
            } else {
                // The peak might be on the right side of the array
                left = mid + 1;
            }
        }

        // 'left' now points to a potential peak element
        return left;
    }
};