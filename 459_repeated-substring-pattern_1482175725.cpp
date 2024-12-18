class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int l = n/2; l >= 1; l--) {
            int repeatCount = n / l;
            string pattern = s.substr(0, l);
            string str = "";
            while (repeatCount--) {
                str += pattern;
            }
            if (str == s)
                return true;
        }
        return false;
    }
};