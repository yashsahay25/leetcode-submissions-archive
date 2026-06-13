class Solution {
public:
    int countGoodSubstrings(string s) {
        int k = 3; // given fixed window length
        int i = 0, j = 0, n = s.length(), count = 0;
        unordered_map<char, int> mp;
        while (j < n) {
            int window = j - i + 1;
            mp[s[j]]++; // mark char in map
            if (window < k)
                j++; // grow the window until it reaches size k
            else if (window == k) {
                if (window == mp.size())
                    count++; // if window size is equal to map size (all distinct)
                // now shift the window
                mp[s[i]]--; 
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
                j++;
            }
        }
        return count;
    }
};