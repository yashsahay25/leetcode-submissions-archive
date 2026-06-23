class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string target = "balloon";

        vector<int> textFreq(26,0);
        vector<int> targetFreq(26,0);

        for (char c : text) {
            textFreq[c - 'a']++;
        }

        for (char c : target) {
            targetFreq[c - 'a']++;
        }

        int count = INT_MAX;
        for(int i=0;i<26;i++){
            if(targetFreq[i]>0){
                count = min(count, textFreq[i]/targetFreq[i]);
            }
        }
        return count == INT_MAX ? 0 : count;
    }
};