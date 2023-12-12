class Solution {
public:
    /*
    General Backtracking Algorithm
    1. main (solveNQueens) function 
    2. backtrack func
    3. isSafe func
    */
    vector<vector<string>> result;
    bool isSafe(int row,int col,vector<string>& board,int n){
        // top-left
        for(int i=row,j=col;i>=0 && j>=0;i--,j--)
            if(board[i][j]=='Q') 
                return false;
        
        // bottom-left
        for(int i=row,j=col;i<n && j>=0;i++,j--)
            if(board[i][j]=='Q') 
                return false;

        // left
        for(int j=col;j>=0;j--)
            if(board[row][j]=='Q') 
                return false;
        
        return true;
    }
    void backtrack(int col,vector<string>& board,int n){
        if(col==n){
            result.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';        // mark
                backtrack(col+1,board,n);   // recurse
                board[row][col]='.';        // un-mark (backtrack)
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        backtrack(0,board,n);
        return result;
    }
};