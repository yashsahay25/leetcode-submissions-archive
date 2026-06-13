class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        
        int start=intervals[0][0];
        int end=intervals[0][1];
        int i=1;
        int n=intervals.size();
        while(i<n)
        {
            if(intervals[i][0]>start && intervals[i][0]>end)
            {
                vector<int> v;
                v.push_back(start);
                v.push_back(end);
                ans.push_back(v);
                start=intervals[i][0];
                end=intervals[i][1];
            }
            else
            {
                start=min(start,intervals[i][0]);
                end=max(end,intervals[i][1]);
            }
            i++;
        }
        i=n-1;
        vector<int> v;
        v.push_back(start);
        v.push_back(end);
        ans.push_back(v);
        
        return ans;
    }
};