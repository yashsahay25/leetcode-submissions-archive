class Solution {
public:
    int k=2;
    unordered_map<int,int> mp;
    int dir[5]={0,1,0,-1,0};
    
    void dfs(vector<vector<int>> &grid, int i, int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size())
            return;
        if(grid[i][j]!=1)
            return;
        mp[k]++;
        grid[i][j]=k;
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    int largestIsland(vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        k=2;
        mp.clear();
        int area=0;        
        //dfs to find every island
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j])
                {
                    dfs(grid,i,j);
					//find the largest island in case there are no 0's in the grid
                    area=max(area,mp[k]);
                    k++;
                }
        
        //store each 0 in queue for bfs
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==0)
                    q.push({i,j});
        //do bfs for each 0
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
			// Unordered Set to make sure the islands are unique
            unordered_set<int> s;
            int tmp=0;
            for(int i=0;i<4;i++)
            {
                int x1 = x+dir[i];
                int y1 = y+dir[i+1];
                
                //check within range or not
                if(x1<0 || y1<0 || x1>=m || y1>=n)    continue;
                if(grid[x1][y1]==0)     continue;
                
                int val=grid[x1][y1];
                if(s.find(val)==s.end()){
                    s.insert(val);
                    tmp+=mp[val];
                }
            }
            area=max(area,tmp+1);
        }
        return area;
    }
};