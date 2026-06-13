class Solution {
public:
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

/*
    vector<vector<string>> ret;
    bool is_valid(vector<string> &board, int row, int col){
        // check col
        for(int i=row;i>=0;--i)
            if(board[i][col] == 'Q') return false;
        // check left diagonal
        for(int i=row,j=col;i>=0&&j>=0;--i,--j)
            if(board[i][j] == 'Q') return false;
        //check right diagonal
        for(int i=row,j=col;i>=0&&j<board.size();--i,++j)
            if(board[i][j] == 'Q') return false;
        return true;
    }
    void dfs(vector<string> &board, int row){
        // exit condition
        if(row == board.size()){
            ret.push_back(board);
            return;
        }
        // iterate every possible position
        for(int i=0;i<board.size();++i){
            if(is_valid(board,row,i)){
                // make decision
                board[row][i] = 'Q';
                // next iteration
                dfs(board,row+1);
                // back-tracking
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
		// return empty if n <= 0
        if(n <= 0) return {{}};
        vector<string> board(n,string(n,'.'));
        dfs(board,0);
        return ret;
    }
*/