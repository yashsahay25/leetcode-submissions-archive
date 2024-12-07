class Solution {
public:
    bool checkValidString(string s) {
        int min = 0, max = 0; // Track the min and max unmatched '('

        for (char c : s) {
            if (c == '(') {
                min++; // New unmatched '('
                max++;
            } else if (c == ')') {
                min--;  // Use one unmatched '(' for this ')'
                max--; // One more ')' reduces the max unmatched '('
            } else if (c == '*') {
                min--;  // Treat '*' as ')' to reduce min count
                max++; // Treat '*' as '(' to increase max count
            }
            if (min < 0)
                min = 0; // we ignore -1 cases
            if (max < 0)
                return false; // More ')' than possible '('
        }

        return min == 0; // Valid if no unmatched '(' left
    }
};