class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // not reachable default case
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
        int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // mark visited

        int pathLen = 1;

        // BFS
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 8; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (x == n - 1 && y == n - 1) return pathLen; // early exit

                    // isReachable check
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] != 0)
                        continue;

                    q.push({nx, ny});
                    grid[nx][ny] = 1; // mark visited
                }
            }
            pathLen++;
        }
        return -1;
    }
};