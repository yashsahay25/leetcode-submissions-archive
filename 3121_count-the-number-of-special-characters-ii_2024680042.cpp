class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lowerSeen(26,-1);
        vector<int> upperSeen(26,-1);

        for(int i=0;i<word.length();i++){
            if(islower(word[i])) lowerSeen[word[i]-'a']=i;
            else {
                if(upperSeen[word[i]-'A']!=-1) continue;
                upperSeen[word[i]-'A']=i;
            }
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(lowerSeen[i]!=-1 && upperSeen[i]!=-1 
                && lowerSeen[i] < upperSeen[i])
                count++;
        }
        return count;
    }
};