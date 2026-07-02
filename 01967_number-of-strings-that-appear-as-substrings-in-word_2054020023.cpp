class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.length();
        unordered_set<string> st;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=i;j<n;j++){
                s += word[j];
                st.insert(s);
            }
        }
        int count=0;
        for(auto& p:patterns){
            if(st.count(p)) count++;
        }
        return count;
    }
};