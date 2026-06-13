class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        // remove 1st & last char
        string str = doubled.substr(1, doubled.size() - 2);
        return str.find(s) != string::npos;
    }
};