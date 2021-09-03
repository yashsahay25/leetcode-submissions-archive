class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        if(mat[0][0]==1)
            return 0;
        int m=mat.size(),n=mat[0].size();
        int dp[m][n];
        
        dp[0][0]=1; //no of ways to reach 1st cell if unblocked
        for (int i = 1; i < m; i++) 
        {
		    if (mat[i][0] == 1) 
            {
			    dp[i][0] = 0;   //blocked
            } 
            else
			    dp[i][0] = dp[i-1][0];
	    }
        //similary for first row
        for (int j = 1; j < n; j++) 
        {
		    if (mat[0][j] == 1) 
            {
			    dp[0][j] = 0;
            }
            else
			    dp[0][j] = dp[0][j-1];
	    }
        
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
            {
                if(mat[i][j]==0)
                    dp[i][j]=dp[i-1][j]+dp[i][j-1]; 
                else
                    dp[i][j]=0;
            }
        return dp[m-1][n-1];
    }
};