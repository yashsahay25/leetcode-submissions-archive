class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int lastIndex = 0, count = 0;
        for (int i = 1; i < intervals.size(); i++) {
            // non-overlapping
            if (intervals[i][0] >= intervals[lastIndex][1]) {
                lastIndex = i; // update lastIndex
            } else {
                count++;
                // we only need to check if the current interval is ending
                // before so we can remove it (not actually remove from array,
                // just ignore it) and update the lastIndex
                if (intervals[i][1] < intervals[lastIndex][1])
                    lastIndex = i;
            }
        }
        return count;
    }
};