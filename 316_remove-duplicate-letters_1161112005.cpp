class Solution
{
    public:
        string removeDuplicateLetters(string s)
        {
            vector<bool> seen(26, false);	// visited array
            vector<int> lastIndex(26, 0);	// store last index of occurance
            stack<char> st;

           	// populate lastIndex array
            for (int i = 0; i < s.length(); i++)
            {
                lastIndex[s[i] - 'a'] = i;
            }

           	// We try to get smaller elements first (lexicographic order)
           	// main logic
            for (int i = 0; i < s.length(); i++)
            {
                if (!seen[s[i] - 'a'])
                {
                	// if curr is not seen before
                   	// if the curr element is smaller than top element, then
                   	// we can remove the top element if it occurs later in the array 
                   	// for that we check lastIndex of top element
                    while (!st.empty() && s[i] < st.top() && lastIndex[st.top() - 'a'] > i)
                    {
                        seen[st.top() - 'a'] = false;	// unmark it
                        st.pop();	// remove from stack
                    }
                    st.push(s[i]);	// push into stack
                    seen[s[i] - 'a'] = true;	// mark visited
                }
            }
            string res = "";
            while (!st.empty())
            {
                res += st.top();
                st.pop();
            }
            reverse(res.begin(), res.end());	// reverse the result to get the correct order
            return res;
        }
};