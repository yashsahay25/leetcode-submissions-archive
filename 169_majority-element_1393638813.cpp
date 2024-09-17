class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int votes = 1; // count
        if (nums.size() == 1)
            return candidate;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == candidate) {
                votes++;
            } else {
                votes--;
                if (votes == 0) {
                    candidate = nums[i];
                    votes++;
                }
            }
        }
        // check if votes > nums.size()/2
        return candidate;
    }
};