class Solution {
public:
    int solve(string& s, int start, int end, int k) {
        // if window is smaller than k
        if (end - start + 1 < k)
            return 0;

        int freq[26] = {0}; // freq array for substring[start...end]
        for (int i = start; i <= end; i++)
            freq[s[i] - 'a']++;

        // iterate over each char of substring
        for (int i = start; i <= end; i++) {
            // if char freq is less than k, it's a breakpoint
            if (freq[s[i] - 'a'] < k) {
                // divide & conquer - split & recurse
                // substr[start...i-1] & substr[i+1...end]
                int leftPart = solve(s, start, i - 1, k);
                int rightPart = solve(s, i + 1, end, k);
                return max(leftPart, rightPart);
            }
        }

        return end - start + 1;
    }
    int longestSubstring(string s, int k) {
        return solve(s, 0, s.length() - 1, k);
    }
};