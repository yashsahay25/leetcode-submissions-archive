class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R= matrix.size();
        int C=matrix[0].size();   
        
        int start= 0;
        int end=R*C-1;          
        
        int mid;
        
        while(start<=end)
        { 
            mid= (start+end)/2;
            if(matrix[mid/C][mid%C]==target)      return 1;  
            else if(matrix[mid/C][mid%C]>target)  end=mid-1;
            else                        start=mid+1;
        }
        return 0;
    }
};