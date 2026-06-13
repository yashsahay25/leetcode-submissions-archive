class Solution
{
    public:
       	// 2 pass approach
       	// Nearest smaller to left
        vector<int> nearestSmallerLeft(vector<int> &heights)
        {
            int n = heights.size();
            vector<int> left(n);
            stack<int> s;	// push index into stack

            for (int i = 0; i < n; i++)
            {
                while (!s.empty() && heights[s.top()] >= heights[i])
                    s.pop();
                if (s.empty())
                    left[i] = -1;
                else
                    left[i] = s.top();
                s.push(i);
            }
            return left;
        }
   	// Nearest smaller to right
    vector<int> nearestSmallerRight(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> right(n);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            if (s.empty())
                right[i] = n;
            else
                right[i] = s.top();
            s.push(i);
        }
        return right;
    }
   	// main function
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left = nearestSmallerLeft(heights);
        vector<int> right = nearestSmallerRight(heights);

       	// calculate max area
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res = max(res, (right[i] - left[i] - 1)*heights[i]);
        }
        return res;
    }
};