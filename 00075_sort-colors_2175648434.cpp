class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0, k = n - 1; // i tracks 0s, k tracks 2s, j moves across

        while (j <= k) { // move until j doesn't cross k
            if (nums[j] == 2) {
                // if curr is 2, swap it to rightmost 2 via k
                swap(nums[j], nums[k]);
                k--; // since 2 has been placed at correct place, move k
            } else if (nums[j] == 0) {
                // if curr is 0, swap it to leftmost 0 via i
                swap(nums[j], nums[i]);
                i++; // since 0 has been placed at correct place, move i
                j++;
            } else { // nums[j]==0
                j++;
            }
        }
    }
};