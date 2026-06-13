class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //recurence relation for top-down
        //dp[i][j]=triangle[i][j] + min(dp[i-1][j-1],dp[i][j-1]);
        
        //using no extra space, bottom-up
        for(int i=triangle.size()-2;i>=0;i--)  //start from 2nd last row & go up
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                triangle[i][j]=min(triangle[i+1][j],triangle[i+1][j+1])+triangle[i][j];
            }
        }
        return triangle[0][0];
    }
};