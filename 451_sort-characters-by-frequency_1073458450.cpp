class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        
        // comparator function
        auto comp = [&mp] (char a, char b) {
            return mp[a] > mp[b] || (mp[a] == mp[b] && a > b);
        };
        
        sort(s.begin(), s.end(), comp);
        
        return s;
        
    }
};