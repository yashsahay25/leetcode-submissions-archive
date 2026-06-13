class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, count = 0, maxLen = 0;
        while (j < nums.size()) {
            if (nums[j] == 0)
                count++;
            while (count > k) {
                if (nums[i] == 0)
                    count--;
                i++;
            }
            if (count <= k) {
                maxLen = max(maxLen, j - i + 1);
            }
            j++;
        }
        return maxLen;
    }
};