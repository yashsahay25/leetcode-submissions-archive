class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // compare current element with last to last position
        // edge case - oth, 1st position
        if (nums.size() <= 2)
            return nums.size();

        int j = 2; // ptr for next position to place a valid element
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[j - 2]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};