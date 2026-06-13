class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval) {
        vector<vector<int>> mergedIntervals;

        if(intervals.size()==0) return {newInterval};

        int start = newInterval[0];
        int end = newInterval[1];

        for (auto interval : intervals) {
            // intervals before newInterval will stay unchanged
            // Part 1 - current interval is before new interval, directly add
            if (interval[1] < start) {
                mergedIntervals.push_back(interval);
            }
            // intervals after newInterval will stay unchanged
            // Part 3 - current interval is after new interval, directly add
            else if (interval[0] > end) {
                mergedIntervals.push_back({start, end});
                start = interval[0];
                end = interval[1];
            }
            // Part 2 - merge new interval
            else if (interval[1] >= start) {
                start = min(start, interval[0]);
                end = max(end, interval[1]);
            }
        }
        // handle last interval
        // mergedIntervals.push_back(intervals.back());
        mergedIntervals.push_back({start, end});
        return mergedIntervals;
    }
};