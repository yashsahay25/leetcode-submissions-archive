class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1]; // descending by 2nd
        }
        return a[0] < b[0]; // ascending by 1st
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        int n = envelopes.size();

        vector<int> temp;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(temp.begin(), temp.end(), envelopes[i][1]);
            if (it == temp.end()) {
                temp.push_back(envelopes[i][1]); // Append
            } else {
                *it = envelopes[i][1]; // Replace first element >= num
            }
        }
        return temp.size();
    }
};