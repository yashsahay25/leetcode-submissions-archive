class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int INF = 1e9;

        // First pass - compare top and left
        // start from top left corner
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] != 0){
                    int top = (i > 0) ? mat[i-1][j] : INF;
                    int left = (j > 0) ? mat[i][j-1] : INF;
                    mat[i][j] = min(top, left) + 1;
                }
            }
        }

        // Second pass - compare bottom and right
        // start from bottom left corner
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(mat[i][j] != 0){
                    int down = (i < n-1) ? mat[i+1][j] : INF;
                    int right = (j < m-1) ? mat[i][j+1] : INF;
                    mat[i][j] = min(mat[i][j], min(down, right) + 1);
                }
            }
        }

        return mat;
    }
};