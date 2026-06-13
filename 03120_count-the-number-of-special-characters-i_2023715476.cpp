class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lowerSeen(26,false);
        vector<bool> upperSeen(26,false);

        for(char c:word){
            if(c>='a') lowerSeen[c-'a']=true;
            else upperSeen[c-'A']=true;
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(lowerSeen[i] && upperSeen[i]) count++;
        }
        return count;
    }
};