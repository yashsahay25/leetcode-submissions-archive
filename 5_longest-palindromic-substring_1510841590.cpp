class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), maxLen = 0, l, r;
        string ans;

        // odd length
        for (int i = 0; i < n; i++) {
            l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            l++, r--; // they had moved one extra places
            if (r - l + 1 > maxLen) {
                maxLen = max(maxLen, r - l + 1);
                ans = s.substr(l, r - l + 1);
            }
        }

        // even length
        for (int i = 0; i < n; i++) {
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            l++, r--; // they had moved one extra places
            if (r - l + 1 > maxLen) {
                maxLen = max(maxLen, r - l + 1);
                ans = s.substr(l, r - l + 1);
            }
        }
        return ans;
    }
};