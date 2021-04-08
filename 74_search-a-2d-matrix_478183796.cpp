class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R= matrix.size();   //row size
        int C=matrix[0].size(); //column size   
        
        //on careful observation, consider the whole 2D array as a single 1D array.
        //It is already sorted.
        //So apply binary search on the matrix
        
        int start=0;
        int end=R*C-1;          
        
        int mid;
        
        while(start<=end)
        { 
            mid= (start+end)/2;
            //matrix[row][col] , in this case are given by
            //row=mid/C and col=mid%C where C is declared above
            if(matrix[mid/C][mid%C]==target)        return 1;   //element found   
            else if(matrix[mid/C][mid%C]>target)    end=mid-1;
            else                                    start=mid+1;
        }
        return 0;
    }
};