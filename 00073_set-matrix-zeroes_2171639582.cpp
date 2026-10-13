class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // 1. Check if the first row originally has any zeroes
        bool makeFirstRowZero = false;
        for(int j=0;j<n;j++){
            if(matrix[0][j]==0){
                makeFirstRowZero = true;
            }
        }

        // 2. Check if the first column originally has any zeroes
        bool makeFirstColZero = false;
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                makeFirstColZero = true;
            }
        }

        // 3. Use the inner matrix to set the flags
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        // 4. Zero out the inner matrix based on the flags
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }

        // 5. Finally, zero out the first row and column if needed
        if(makeFirstRowZero){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }

        if(makeFirstColZero){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};