class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, 0));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            visited[i][0] = 1;

            pq.push({heightMap[i][n - 1], i, n - 1});
            visited[i][n - 1] = 1;
        }

        for (int j = 0; j < n; j++) {
            pq.push({heightMap[0][j], 0, j});
            visited[0][j] = 1;

            pq.push({heightMap[m - 1][j], m - 1, j});
            visited[m - 1][j] = 1;
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        int water = 0;

        while (!pq.empty()) {
            auto [currHeight, x, y] = pq.top();
            pq.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny])
                    continue;

                visited[nx][ny] = 1;
                // nbr >= current --> no water stored
                // nbr < current --> curr will become wall
                water += max(currHeight - heightMap[nx][ny], 0);
                pq.push({max(heightMap[nx][ny], currHeight), nx, ny});
            }
        }
        return water;
    }
};