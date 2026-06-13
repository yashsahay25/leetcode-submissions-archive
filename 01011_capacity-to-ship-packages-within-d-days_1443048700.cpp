class Solution {
public:
    int daysToLoad(vector<int>& w, int capacity) {
        int days = 1, load = 0;
        for (int i = 0; i < w.size(); i++) {
            if (load + w[i] > capacity) {
                days++;
                load = w[i];
            } else {
                load += w[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(),0);

        int ans;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (daysToLoad(weights, mid) <= days) {
                ans = mid;
                hi = mid - 1; // continue searching
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};