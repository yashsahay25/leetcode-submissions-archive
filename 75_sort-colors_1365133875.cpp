class Solution {
public:
    void sortColors(vector<int>& nums) {
        // dnf algo
        int start = 0, mid = 0, end = nums.size() - 1;

        // traverse until mid crosses end
        while (mid <= end) {
            if (nums[mid] == 2) {
                swap(nums[mid], nums[end]);
                end--;
            } else if (nums[mid] == 0) {
                swap(nums[mid], nums[start]);
                start++, mid++;
            } else {
                // no swap, just move mid
                mid++;
            }
        }
    }
};