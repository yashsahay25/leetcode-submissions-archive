class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0, res = 0;
        for (int x : nums) {
            if (x == 1)
                curr++, res = max(res, curr);
            else
                curr = 0;
        }
        return res;
    }
};