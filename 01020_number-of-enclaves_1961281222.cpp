class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // Boundary + check
        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != 1)
            return;

        // Mark as safe
        grid[x][y] = 2;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            dfs(x + dx[k], y + dy[k], grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // Step 1: Mark boundary-connected 1's
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) dfs(i, 0, grid);
            if (grid[i][m - 1] == 1) dfs(i, m - 1, grid);
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) dfs(0, j, grid);
            if (grid[n - 1][j] == 1) dfs(n - 1, j, grid);
        }

        // Now all '1' cells left behid will be landlocked and our answer

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    count++;
            }
        }
        return count;
    }
};