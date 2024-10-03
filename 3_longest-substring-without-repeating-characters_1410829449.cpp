class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // variable size sliding window
        int n = s.length();
        int i = 0, j = 0, maxLen = 0;
        unordered_map<char, int> mp;
        while (j < n) {
            mp[s[j]]++;
            while (j - i + 1 > mp.size()) {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            if (j - i + 1 == mp.size())
                maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};