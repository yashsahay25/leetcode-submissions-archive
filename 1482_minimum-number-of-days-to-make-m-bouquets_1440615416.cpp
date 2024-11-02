class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay, int currDay, int m, int k) {
        int pick = 0, totalBouquets = 0;
        for (int j = 0; j < bloomDay.size(); j++) {
            if (bloomDay[j] <= currDay) {
                pick++;
                if (pick == k) {
                    totalBouquets++;
                    pick = 0; // Reset for next bouquet
                }
            } else {
                pick = 0;
            }
        }
        return totalBouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < (long long)m * k)
            return -1;

        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canMakeBouquets(bloomDay, mid, m, k)) {
                ans = mid; // Possible solution, try for an earlier day
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};