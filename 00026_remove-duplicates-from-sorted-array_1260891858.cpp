class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; // start at first element
        // traverse arr using j to find next unique number
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                // if unique found, put it next to i
                // so that i, i+1... are unique numbers
                nums[i + 1] = nums[j];
                i++; // then jump to that element
            }
        }
        // the loop ends at i, reqd len will be i+1
        return i + 1;
    }
};