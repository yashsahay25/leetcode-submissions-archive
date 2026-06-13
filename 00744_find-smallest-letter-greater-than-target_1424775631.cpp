class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        int lo = 0, hi = letters.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (letters[mid] > target) {
                ans = letters[mid];
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};