class Solution {
public:
    int findMax(vector<vector<int>>& mat,int col){
        int maxRow = 0;
        for (int row = 1; row < mat.size(); row++) {
            if (mat[row][col] > mat[maxRow][col]) {
                maxRow = row;
            }
        }
        return maxRow;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=(lo+hi)/2; // to track col
            int row=findMax(mat,mid); // get row of maxElement

            int left = mid-1>=0 ? mat[row][mid-1] : -1;
            int right = mid+1<n ? mat[row][mid+1] : -1;

            if(mat[row][mid]>left && mat[row][mid]>right)
                return {row,mid};
            else if(mat[row][mid]<left)
                hi=mid-1;
            else
                lo=mid+1;
        }
        return {-1,-1};
    }
};