class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // instead of starting with each 1, we start with all 0's together
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> result(m, vector<int>(n, -1));

        queue<pair<int, int>> q; // {i,j}
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0; // mark as visited, dist=0
                    q.push({i, j}); // add to queue
                }
            }
        }
        // direction vector
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                // check bounds and unvisited
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && result[nx][ny] == -1) {
                    result[nx][ny] = result[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return result;
    }
};