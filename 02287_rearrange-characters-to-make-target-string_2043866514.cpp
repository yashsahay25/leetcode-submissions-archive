class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> strFreq(26,0);
        vector<int> targetFreq(26,0);

        for (char c : s) {
            strFreq[c - 'a']++;
        }

        for (char c : target) {
            targetFreq[c - 'a']++;
        }

        int count = INT_MAX;
        for(int i=0;i<26;i++){
            if(targetFreq[i]>0){
                count = min(count, strFreq[i]/targetFreq[i]);
            }
        }
        return count == INT_MAX ? 0 : count; 
    }
};