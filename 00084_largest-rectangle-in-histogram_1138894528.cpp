class Solution
{
    public:
        int largestRectangleArea(vector<int> &heights)
        {
            stack<int> s;
            heights.push_back(0);
            int maxSize = 0;
            for (int i = 0; i < heights.size(); i++)
            {
                if (s.empty() || heights[i] >= heights[s.top()])
                {
                    s.push(i);
                }
                else
                {
                    int temp = heights[s.top()];
                    s.pop();
                    maxSize = max(maxSize, temp *(s.empty() ? i : i - 1 - s.top()));
                    i--;
                }
            }
            return maxSize;
        }
};