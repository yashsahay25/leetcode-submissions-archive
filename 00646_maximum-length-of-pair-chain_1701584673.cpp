class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1]; // sort by end time
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        int s = pairs[0][0], e = pairs[0][1];

        int count = 1;
        for (int i = 1; i < pairs.size(); i++) {
            int s1 = pairs[i][0], e1 = pairs[i][1];
            if (e < s1) {
                count++;
                s = s1, e = e1;
            }
        }
        return count;
    }
};