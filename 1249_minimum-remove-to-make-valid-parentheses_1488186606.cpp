class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();

        // traverse L2R, count open, eliminate close brackets
        string temp;
        int open = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
                temp.push_back(s[i]);
            } else if (s[i] == ')') {
                if (open > 0) {
                    open--;
                    temp.push_back(s[i]);
                }
            } else {
                temp.push_back(s[i]);
            }
        }

        // traverse R2L, eliminate open brackets
        string res;
        for (int i = temp.size() - 1; i >= 0; i--) {
            if (temp[i] == '(' && open > 0) {
                open--;
            } else {
                res.push_back(temp[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};