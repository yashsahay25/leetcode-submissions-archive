class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;

        // declare & populate the set
        unordered_set<int> st(nums.begin(), nums.end());

        int maxLen = 1;
        for (int num : nums) {
            // if prev is not found in set, it means current is actually the
            // start of the sequence
            if (!st.count(num - 1)) {
                int currentNum = num;
                int len = 1;
                // starting from current, keep iterating until seq breaks
                while (st.count(currentNum + 1)) {
                    currentNum++;
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};