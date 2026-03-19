class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // boundary check
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '0')
            return;

        // Mark visited
        grid[x][y] = '0';

        // Direction arrays
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        // Explore all 4 directions
        for (int k = 0; k < 4; k++) {
            int newX = x + dx[k];
            int newY = y + dy[k];
            dfs(newX, newY, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int numIslands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') { // visit only islands
                    dfs(i, j, grid);
                    numIslands++;
                }
            }
        }
        return numIslands;
    }
};