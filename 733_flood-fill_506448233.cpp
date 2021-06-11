class Solution 
{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor)
            dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }

    void dfs(vector<vector<int>>& image, int i, int j, int c0, int c1) 
    {
        //modify the same matrix
        //c0 : color0 - current color
        //c1 : color0 - new color
        //check bounds
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != c0) 
            return;
        
        image[i][j] = c1;
        dfs(image, i, j - 1, c0, c1);
        dfs(image, i, j + 1, c0, c1);
        dfs(image, i - 1, j, c0, c1);
        dfs(image, i + 1, j, c0, c1);
    }
};