class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // compare current element with last to last position
        // edge case - oth, 1st position

        int j = 0;
        for (auto x : nums) {
            if (j == 0 || j == 1 || x != nums[j - 2]) {
                nums[j] = x;
                j++;
            }
        }
        return j;
    }
};