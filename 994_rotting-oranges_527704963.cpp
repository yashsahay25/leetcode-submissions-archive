class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        
        int ans = -1, n = grid.size(), m = grid[0].size(),fresh=0;
        
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 2)
                    q.push({i, j}), grid[i][j] = 0;
                if (grid[i][j] == 1)
                    fresh++;
            }
        }

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int i = q.front().first, j = q.front().second;
                q.pop();
                for (int k = 0; k < 4; ++k)
                {
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 0 || y < 0 || x >= n || y >= m || !grid[x][y])
                        continue;
        
                    grid[x][y] = 0;
                    q.push({x, y});
                    fresh--;
                }
            }
            ++ans;
        }
        
        if(fresh>0) return -1; //if fresh>0 that means there are fresh oranges left
        if(ans==-1) return 0; //we initialised with -1, so if there were no oranges it'd take 0 mins.
        return ans;
    }
};