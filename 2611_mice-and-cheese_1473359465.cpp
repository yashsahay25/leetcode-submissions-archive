class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<pair<int, int>> diffAndIndex;

        for (int i = 0; i < n; i++)
            diffAndIndex.push_back({reward1[i] - reward2[i], i});

        sort(diffAndIndex.rbegin(), diffAndIndex.rend());

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (i < k)
                sum += reward1[diffAndIndex[i].second];
            else
                sum += reward2[diffAndIndex[i].second];
        }
        return sum;
    }
};