class Solution {
public:
    bool checkMatrix(vector<vector<char>>& board,string word,int row,int col,int index,int m,int n) {

        // if index reaches at the end that means we have found the word
        if (index == word.length())
            return true;

        // boundary condition checks
        if (row < 0 || col < 0 || row == m || col == n || 
        board[row][col] != word[index] || 
        board[row][col] == '!')
            return false;

        char c = board[row][col];
        board[row][col] = '!'; // mark as visited

        // top direction
        bool top = checkMatrix(board, word, row - 1, col, index + 1, m, n);
        // right direction
        bool right = checkMatrix(board, word, row, col + 1, index + 1, m, n);
        // bottom direction
        bool bottom = checkMatrix(board, word, row + 1, col, index + 1, m, n);
        // left direction
        bool left = checkMatrix(board, word, row, col - 1, index + 1, m, n);

        board[row][col] = c; // undo change

        return top || right || bottom || left;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        int index = 0;
        // First search the first character
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[index]) {
                    if (checkMatrix(board, word, i, j, index, m, n))
                        return true;
                }
            }
        }

        return false;
    }
};