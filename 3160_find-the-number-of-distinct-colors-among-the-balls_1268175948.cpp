class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballMap;  // ball, color
        unordered_map<int, int> colorMap; // color, count

        int q = queries.size();
        vector<int> res;
        for (int i = 0; i < q; i++) {
            int x = queries[i][0], y = queries[i][1];

            // check if ball already colored
            int colorY = ballMap[x];
            if (colorMap.find(colorY) != colorMap.end()) {
                colorMap[colorY]--; // reduce exisiting color count
                if (colorMap[colorY] == 0)
                    colorMap.erase(colorY); // if count becomes 0, remove that color
            }

            ballMap[x] = y; // ball x has color y
            colorMap[y]++;  // update count of color y
            res.push_back(
                colorMap
                    .size()); // number of distinct colors = size of color map
        }
        return res;
    }
};