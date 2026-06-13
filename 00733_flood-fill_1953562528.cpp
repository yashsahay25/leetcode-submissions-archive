class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& grid, int oldColor,
             int newColor) {
        int n = grid.size();
        int m = grid[0].size();

        // boundary check
        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != oldColor)
            return;

        grid[x][y] = newColor; // assign color

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        // flood fill neighbors
        for (int k = 0; k < 4; k++) {
            dfs(x + dx[k], y + dy[k], grid, oldColor, newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int oldColor = image[sr][sc];

        // Given cell already having color, so stop
        if (oldColor == color)
            return image;

        dfs(sr, sc, image, oldColor, color);
        return image;
    }
};