class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>> mergedIntervals;
         
         sort(intervals.begin(),intervals.end());
         auto start = intervals[0][0];
         auto end = intervals[0][1];
         for(int i=1;i<intervals.size();i++)
         {
            if(intervals[i][0]<=end)
            {
                if(end<intervals[i][1])
                    end = intervals[i][1];
            }
            else
            {
                mergedIntervals.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
         }
         mergedIntervals.push_back({start,end});
         return mergedIntervals;
    }
};