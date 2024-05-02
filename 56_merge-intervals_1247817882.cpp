class Solution
{
    public:
        vector<vector < int>> merge(vector<vector < int>> &intervals)
        {
            stack<vector < int>> stk;
            sort(intervals.begin(), intervals.end());	// sort on start time

            stk.push(intervals[0]);

            for (int i = 1; i < intervals.size(); i++)
            {
                vector<int> curr = intervals[i];
                vector<int> &top = stk.top();	// copy by ref (else won't work)

                if (curr[0] <= top[1])
                {
                    top[1] = max(curr[1], top[1]);
                }
                else
                {
                    stk.push(curr);
                }
            }

            vector<vector < int>> res;
            while (!stk.empty())
            {
                res.push_back(stk.top());
                stk.pop();
            }
            reverse(res.begin(), res.end());
            return res;
        }
};