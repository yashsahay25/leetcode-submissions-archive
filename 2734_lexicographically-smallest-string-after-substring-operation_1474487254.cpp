class Solution {
public:
    string smallestString(string s) {
        int n = s.size(), i = 0;
        while (i < n && s[i] == 'a') // skip all a's at the front
            i++;
        if (i >= n) { // if you reach end, then just replace last a to z
            s[s.size() - 1] = 'z';
            return s;
        }
        while (i < n && s[i] != 'a') { // reduce each char till you get a
            s[i]--;
            i++;
        }
        return s;
    }
};