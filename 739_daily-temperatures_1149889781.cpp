class Solution
{
    public:
        vector<int> dailyTemperatures(vector<int> &temperatures)
        {
            int n = temperatures.size();
            // stack<pair<int, int>> s;	// store value,index in stack
            stack<int> s; // only index
            vector<int> ans(n, 0);	// default to 0, as per ques

           	// ans[i] will be NGR_index - Element_index
           	// start from right to left
            for (int i = n - 1; i >= 0; i--)
            {
               	// pop until empty or smaller
                while (!s.empty() && temperatures[s.top()] <= temperatures[i])
                    s.pop();
               	// if becomes empty
                if (s.empty())
                    ans[i] = 0;
               	// store NGR's index
                else
                    ans[i] = s.top();

               	// at the end, add to stack    
                s.push(i);
            }
           	// to find number of days you have to wait, do below
            for (int i = 0; i < n; i++)
            {
                if (ans[i] > 0)
                    ans[i] = ans[i] - i;
            }
            return ans;
        }
};