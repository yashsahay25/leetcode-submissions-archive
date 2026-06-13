class Solution {
public:
    int maxDepth(string s) {
        int maxSize=0;
        stack<char> st;
        if(s.length()==0) return 0;
        for(char c:s){
            if(st.size()>maxSize) maxSize = st.size();
            if(c=='(') st.push(c);
            else if(c==')') st.pop();
        }
        return maxSize;
    }
};