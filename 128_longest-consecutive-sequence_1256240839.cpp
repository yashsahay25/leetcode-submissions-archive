class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int n : nums) { // populate the map
            mp[n] = 1;
        }

        int maxLen = 0;
        for (int n : nums) {
            int len = 0;
            int current = n;

            // if prev is not found in map, it means current is actually the
            // start of the sequence
            if (mp.find(current - 1) == mp.end()) {
                // starting from current, keep iterating until seq breaks
                while (mp.find(current) != mp.end()) {
                    len++;
                    current++;
                }
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};