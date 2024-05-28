class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            // compare current interval end with existing ka start
            // merge them, & update end
            if(intervals[i][0]<=end){
                end=max(end,intervals[i][1]);
            }
            else{
                // new interval found, push existing start,end
                mergedIntervals.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        mergedIntervals.push_back({start,end}); // handle last element
        return mergedIntervals;
    }
};