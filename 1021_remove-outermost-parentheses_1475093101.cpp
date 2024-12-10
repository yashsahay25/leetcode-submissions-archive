class Solution {
public:
    string removeOuterParentheses(string s) {
        int i = 0, count = 0;
        string res;
        while (i < s.length()) {
            if (s[i] == '(') {
                // if its the first char ie. count is currently 0, we don't include it
                if (count > 0) res += s[i];
                count++;
            } else {
                count--;
                // if its the last char ie. count is currently 0, we don't include it
                if (count > 0) res += s[i];
            }
            i++;
        }
        return res;
    }
};