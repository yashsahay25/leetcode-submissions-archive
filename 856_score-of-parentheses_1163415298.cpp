class Solution
{
    public:
        int scoreOfParentheses(string s)
        {
            stack<int> stk;
            int score = 0;

            for (char c: s)
            {
               	// opening bracket
                if (c == '(')
                {
                    stk.push(0);	// push 0 for open
                }
               	// closing bracket
                else
                {
                    int val = 0;
                   	// pop until we get opening bracket &add values
                    while (stk.top() != 0)
                    {
                        val += stk.top();
                        stk.pop();
                    }
                   	// if there were no elements before we got the open bracket
                   	// ie. case (), then val should 1
                   	// else 2*val
                    val = max(2 *val, 1);
                    stk.pop();
                    stk.push(val);	// updated val (either 1 or 2*() vala case)
                }
            }
            while (!stk.empty())
            {
                score += stk.top();
                stk.pop();
            }
            return score;
        }
};