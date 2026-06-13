class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk; // store index
        unordered_set<int> indexToRemove;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                if (stk.empty()) {
                    indexToRemove.insert(i);
                } else {
                    stk.pop();
                }
            }
        }
        // store index of unmatched open brackets
        while (!stk.empty()) {
            indexToRemove.insert(stk.top());
            stk.pop();
        }
        // form the answer
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (indexToRemove.find(i) == indexToRemove.end()) {
                res += s[i];
            }
        }
        return res;
    }
};