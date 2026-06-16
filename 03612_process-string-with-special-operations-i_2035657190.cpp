class Solution {
public:
    string processStr(string s) {
        string result = "";
        for (auto it : s) {
            if (it >= 'a' && it <= 'z')
                result += it;
            else if (it == '*')
                result = result.substr(0, result.size() - 1);
            else if (it == '#')
                result = result + result;
            else
                reverse(result.begin(), result.end());
        }
        return result;
    }
};