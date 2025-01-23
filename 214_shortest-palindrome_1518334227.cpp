class Solution {
public:
    int lps(string str) {
        int n = str.size();
        vector<int> lps(n, 0);
        int i = 1, len = 0;
        while (i < n) {
            if (str[i] == str[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len > 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        // we only need the longest prefix length, so return lps[last]
        return lps[n - 1];
    }
    string shortestPalindrome(string s) {
        // optimal code - using LPS part of kmp algo
        string rev = s;
        reverse(rev.begin(), rev.end());

        int k = lps(s + "#" + rev); // longestPrefixLen
        return rev.substr(0, s.length() - k) + s;
    }
};