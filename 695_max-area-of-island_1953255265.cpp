class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& grid, int& count) {
        int n = grid.size();
        int m = grid[0].size();

        // boundary check
        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0)
            return;

        grid[x][y] = 0;
        count++;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int newX = x + dx[k];
            int newY = y + dy[k];
            dfs(newX, newY, grid, count);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    dfs(i, j, grid, count);
                    maxCount = max(count, maxCount);
                }
            }
        }
        return maxCount;
    }
};