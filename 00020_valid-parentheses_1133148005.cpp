class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            // opening bracket
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty())
                    return false; // Stack is empty, unmatched closing bracket
                
                // matching closing bracket
                if (c == ')' && st.top() == '(') //) closing bracket
                    st.pop();
                else if (c == '}' && st.top() == '{') // } closing bracket
                    st.pop();
                else if (c == ']' && st.top() == '[') // ] closing bracket
                    st.pop();
                else
                    return false; // mismatched closing bracket
            }
        }
        return st.empty();
    }
};