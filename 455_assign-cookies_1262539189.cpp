class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, count = 0;
        while (i < g.size() && j < s.size()) {
            // if cookie is required size, select it and move ahead (i++)
            if (s[j] >= g[i]) {
                count++;
                i++;
            }
            // if the above condition is not met, then we only move j (next
            // cookie) and in next iteration, i & (j+1) combination is checked
            j++;
        }
        return count;
    }
};