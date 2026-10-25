class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int lead = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != majority) {
                lead--;
                if (lead == 0) {
                    majority = nums[i];
                    lead = 1;
                }
            } else {
                lead++;
                if (lead > nums.size() / 2) break;
            }
        }
        return majority;
    }
};