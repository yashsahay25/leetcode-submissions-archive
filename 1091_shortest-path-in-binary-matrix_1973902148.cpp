class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // not reachable default case
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        // distance vector
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
        int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 1;

        // BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 8; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (x == n-1 && y == n-1) return dist[x][y]; // early exit
                
                // isReachable check
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] != 0)
                    continue;

                if (dist[x][y] + 1 < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return dist[n - 1][n - 1] == 1e9 ? -1 : dist[n - 1][n - 1];
    }
};