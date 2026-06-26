class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int leadVote = 0;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] == target)
                    leadVote++;
                else
                    leadVote--;
                    
                if (leadVote > 0)
                    count++;
            }
        }
        return count;
    }
};