class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> seen(word.begin(),word.end());
        
        int count=0;
        for(int i=0;i<26;i++){
            if(seen.count('a'+i) && seen.count('A'+i)) count++;
        }
        return count;
    }
};