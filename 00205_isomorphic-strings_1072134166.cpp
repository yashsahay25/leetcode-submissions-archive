class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // mapping should be one-one only from both sides
        // so we maintain 2 maps
        if(s.length()!=t.length()) return false;
        unordered_map<char, char> mp, mp2;
        for (int i=0; i<s.length(); ++i) {
            // s to t mapping
            if (mp[s[i]] && mp[s[i]]!=t[i]) return false;
            // t to s mapping
            if (mp2[t[i]] && mp2[t[i]]!=s[i]) return false;
            
            mp[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        return true;
    }
};