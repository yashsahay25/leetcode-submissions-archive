class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int unmatched=0;
        for(char c:s){
            if(c=='(') stk.push(c);
            else{
                if(!stk.empty()) stk.pop();
                else unmatched++;
            }
        }
        return stk.size()+unmatched;
    }
};