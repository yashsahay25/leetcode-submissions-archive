class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return {};

        vector<vector<int>> merged;

        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if (currStart <= end) {
                // merged interval found
                end = max(end, currEnd);
            } else {
                // new interval found
                merged.push_back({start, end});
                start = currStart;
                end = currEnd;
            }
        }

        // handle last case
        merged.push_back({start, end});
        return merged;
    }
};