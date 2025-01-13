class Solution {
public:
    string rle(string s) {
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int freq = 1;
            while (i < n - 1 && s[i] == s[i + 1]) {
                i++;
                freq++;
            }
            ans += to_string(freq) + string(1, ch);
        }
        return ans;
    }

    string countAndSay(int n) {
        if (n == 1)
            return "1";
        return rle(countAndSay(n - 1));
    }
};