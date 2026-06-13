class Solution {
public:
    bool isSafe(int row,int col,char c,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            // check row
            if(board[row][i]==c)  return false;
            
            // check column
            if(board[i][col]==c)  return false;
            
            // check sub-matrix
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)  
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                // pick empty cell
                if(board[i][j]=='.'){
                    // try each digit at that empty place
                    for(char c='1';c<='9';c++){
                        if(isSafe(i,j,c,board)){
                            board[i][j]=c; // mark
                            
                            if(solve(board)) // recurse
                                return true; // return on first solution itself
                            else
                                board[i][j]='.'; // if not true, backtrack
                        }
                    }
                    // no digit found which can be placed
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};