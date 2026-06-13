class Solution
{
    public:
        int longestValidParentheses(string s)
        {
           	// open-close bracket count method
           	// Time O(n) Space O(1)

            int n = s.length();
            int open = 0, close = 0;
            int len = 0;

           	// left to right
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '(')
                    open++;
                else
                    close++;

                /*conditions which hold good here:
                    both equal --> string is valid upto that index
                    close > open --> string is invalid for sure
                    open > close --> string might become valid in future iteration, so ignore this case
                */
                if (open == close)
                    len = max(len, open + close);
                else if (close > open)
                    open = close = 0;	// reset counts (start a new string)
            }

            open = close = 0;
           	// right to left
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == '(')
                    open++;
                else
                    close++;

               	// reverse the above conditions &traversal
                if (open == close)
                    len = max(len, open + close);
                else if (open > close)
                    open = close = 0;	// reset counts (start a new string)
            }
            return len;
        }
};