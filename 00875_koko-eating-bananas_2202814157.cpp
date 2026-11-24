class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        int ans = hi;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            int hours = 0;
            for (auto pile : piles) {
                hours += pile % mid == 0 ? pile / mid : (int)pile / mid + 1;
                if (hours > h)
                    break;
            }
            if (hours <= h) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};