class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // x is start of a consecutive seq if (x-1) is not present
        // if x starts a seq, then (x+1) is also part of that seq & so on
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLen = 0;
        for (int x : nums) {
            if (s.find(x - 1) == s.end()) {
                int len = 1;
                int current = x;
                while (s.find(current + 1) != s.end()) {
                    current++;
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};