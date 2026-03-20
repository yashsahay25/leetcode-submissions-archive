class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Multi source BFS
        // all initial rotten oranges will start rotting nbrs together at t=0
        int n = grid.size();
        int m = grid[0].size();

        queue<tuple<int, int, int>> q; // {row,col,time}

        int dx[4] = {1, 0, -1, 0};  // direction grid
        int dy[4] = {0, -1, 0, 1};

        int fresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});  // push all initial rotten oranges
                } else if (grid[i][j] == 1) {
                    fresh++;            // fresh oranges counter
                }
            }
        }

        if (fresh == 0)
            return 0; // stop code early as no fresh oranges to rot

        int maxTime = 0;
        int count = 0;

        while (!q.empty()) {
            auto [x, y, time] = q.front();
            q.pop();

            maxTime = max(maxTime, time);

            for (int k = 0; k < 4; k++) {
                int nbrX = x + dx[k];
                int nbrY = y + dy[k];

                if (nbrX >= 0 && nbrY >= 0 && nbrX < n && nbrY < m &&
                    grid[nbrX][nbrY] == 1) {
                    grid[nbrX][nbrY] = 2;
                    q.push({nbrX, nbrY, time + 1});
                    count++;
                }
            }
        }
        return (count == fresh) ? maxTime : -1;
    }
};