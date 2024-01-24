class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st; // store index of starting opening bracket
        st.push(-1);   // will help for initial comparison

        int len = 0; // answer variable
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i); // for opening bracket, push its index
            } else {
                if (!st.empty())
                    st.pop(); // for closing bracket, pop the stack
                if (!st.empty())
                    len = max(len, i - st.top()); // update len
                else
                    st.push(i); // push index
            }
        }
        return len;
    }
};