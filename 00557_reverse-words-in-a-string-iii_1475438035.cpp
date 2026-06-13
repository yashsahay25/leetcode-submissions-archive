class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int startIndex = 0, endIndex = 0;
        while (endIndex < n) {
            while (endIndex < n && s[endIndex] != ' ') {
                endIndex++;
            }
            reverse(s.begin() + startIndex, s.begin() + endIndex);
            endIndex++;
            startIndex = endIndex;
        }
        return s;
    }
};