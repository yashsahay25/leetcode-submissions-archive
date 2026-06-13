class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int freq = 0, i = 0, j = 0;
        string temp;
        unordered_map<string, int> mpp;
        unordered_map<char, int> mp;

        while (j < s.length()) {
            temp += s[j]; // to maintain substring
            mp[s[j]]++;
            if (j - i + 1 < minSize)
                j++;
            else if (j - i + 1 == minSize) {
                if (mp.size() <= maxLetters)
                    mpp[temp]++;
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                temp.erase(temp.begin());
                i++;
                j++;
            }
        }
        for (auto it : mpp)
            freq = max(freq, it.second);
        return freq;
    }
};