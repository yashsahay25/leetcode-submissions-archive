class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size();
        int n=matrix[0].size();
        int top=0,down=m-1,left=0,right=n-1;
        int dir=0; //0->1->2->3
        
        while(top<=down and left<=right)
        {
            if(dir==0)
            {
                for(int i=left;i<=right;i++)
                    res.push_back(matrix[top][i]);
                top++;
            }
            if(dir==1)
            {
                for(int i=top;i<=down;i++)
                    res.push_back(matrix[i][right]);
                right--;
            }
            if(dir==2)
            {
                for(int i=right;i>=left;i--)
                    res.push_back(matrix[down][i]);
                down--;
            }
            if(dir==3)
            {
                for(int i=down;i>=top;i--)
                    res.push_back(matrix[i][left]);
                left++;
            }
            dir=(dir+1)%4;
        }
        return res;
    }
};