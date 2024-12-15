class Solution {
public:
    vector<int> calcLps(string pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0); // lps[0]=0;
        int i = 1, j = 0;      // i goes from 1 to m-1
        while (i < m) {
            if (pattern[i] == pattern[j]) {
                j++;        // update length
                lps[i] = j; // set that length as lps of i
                i++;
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    int kmp(string text, string pattern) {
        vector<int> lps = calcLps(pattern);
        int n = text.size();
        int m = pattern.size();
        int i = 0, j = 0;
        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }
            if (j == m) { // answer found
                return i - j;
            } else if (i < n && text[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j - 1]; // jump back
                } else {
                    i++; // move i ahead
                }
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0; // Handle empty pattern case
        return kmp(haystack, needle);
    }
};