class Solution
{
    public:
        vector<int> findAnagrams(string s, string p)
        {
            vector<int> res;
            int i = 0, j = 0;
            unordered_map<char, int> sMap;
            unordered_map<char, int> pMap;
            int k = p.length();

            for (char c: p) pMap[c]++;

            while (j < s.length())
            {
                sMap[s[j]]++;
                if (j - i + 1 < k) j++;
                else if (j - i + 1 == k)
                {
                    if (sMap == pMap) res.push_back(i);
                   	// now slide the window
                    sMap[s[i]]--;
                    if (sMap[s[i]] == 0)
                        sMap.erase(s[i]);
                    i++;
                    j++;
                }
            }
            return res;
        }
};