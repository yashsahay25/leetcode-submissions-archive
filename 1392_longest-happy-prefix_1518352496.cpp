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
        return lps[n - 1];
    }
    string longestPrefix(string s) {
        int k = lps(s); // ending index of longest prefix which is also suffix
        return s.substr(0, k);
    }
};