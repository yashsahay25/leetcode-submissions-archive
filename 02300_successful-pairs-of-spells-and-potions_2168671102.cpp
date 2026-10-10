class Solution {
public:
    int search(vector<int>& potions, int spell, long long success) {
        int lo = 0, hi = potions.size() - 1;

        // initialise with m instead of -1, so direct m-j becomes 0
        int firstValidIndex = potions.size();

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            long long product = (long long)potions[mid] * spell;

            if (product < success) {
                lo = mid + 1;
            } else if (product >= success) {
                firstValidIndex = mid;
                hi = mid - 1;
            }
        }
        return firstValidIndex;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        vector<int> res;
        int n = spells.size();
        int m = potions.size();

        sort(potions.begin(), potions.end());

        for (int i = 0; i < n; i++) {
            int j = search(potions, spells[i], success);
            // all elements will be success [j...m-1] = m-1-j+1
            res.push_back(m - j);
        }
        return res;
    }
};