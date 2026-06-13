class Solution {
public:
    int calc(vector<int>& piles, int m, int h) {
        long long pTotal = 0;
        for (int p : piles) {
            pTotal += (p + m - 1) / m; // Manual ceiling calculation
            if (pTotal > h)
                return pTotal; // Early exit to prevent overflow
        }
        return pTotal;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // concept: bs on answers
        // possible range: [1 to arr_max]

        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        int ans = hi;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int hh = calc(piles, mid, h);

            if (hh <= h) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};