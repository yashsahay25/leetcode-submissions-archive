class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // Boundary + check
        if (x < 0 || y < 0 || x >= n || y >= m || board[x][y] != 'O')
            return;

        // Mark as safe
        board[x][y] = 'S';

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            dfs(x + dx[k], y + dy[k], board);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // We will use reverse engineering to solve this problem
        // any cell which is neighbour of boundary 'O' cell will not be captured
        // so mark them as safe during DFS

        // Step 1: Mark boundary-connected O's
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][m-1] == 'O') dfs(i, m-1, board);
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(0, j, board);
            if (board[n-1][j] == 'O') dfs(n-1, j, board);
        }
        
        // Now all 'O' cells left behind will be captured
        // And we can replace Safe cells back with 'O'

        // Step 2: Flip and restore
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';   // captured
                else if (board[i][j] == 'S')
                    board[i][j] = 'O';   // restore safe
            }
        }
    }
};