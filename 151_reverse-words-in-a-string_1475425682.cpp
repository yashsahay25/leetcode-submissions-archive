class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(),s.end());
        int l = 0, r = 0, i = 0;
        while (i < n) {
            while (i < n && s[i] == ' ')
                i++; // skip spaces
            if (i == n)
                break; // if reach end

            while (i < n && s[i] != ' ')
                s[r++] = s[i++]; // copy elements of the word at correct place

            reverse(s.begin() + l, s.begin() + r); // reverse word

            s[r] = ' '; // add space at end of word
            r++;

            l = r; // shift l to r for next word
            i++;
        }
        s.resize(r - 1); // resize s to exclude space at end
        return s;
    }
};