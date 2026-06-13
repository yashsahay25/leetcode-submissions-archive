class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> s;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char current = board[i][j];
                if(current!='.'){
                    string row = "row"+to_string(i)+current;
                    if(s.count(row))    return false;
                    s.insert(row);

                    string col = "col"+to_string(j)+current;
                    if(s.count(col))    return false;
                    s.insert(col);

                    string box = "box"+to_string(i/3)+to_string(j/3)+current;
                    if(s.count(box))    return false;
                    s.insert(box);
                }
            }
        }
        return true;
    }
};