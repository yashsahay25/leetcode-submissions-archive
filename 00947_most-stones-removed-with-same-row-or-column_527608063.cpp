class Solution {
public:
    
    int count = 0;
    void DFS(int currentStone, vector<vector<int>> &stones, vector<int> &vis)
    {
        
        vis[currentStone] = 1;
        
        int row = stones[currentStone][0];
        int col = stones[currentStone][1];
        
        for (int j = 0;j<stones.size();j++) {
            if (!vis[j] && (stones[j][0] == row || stones[j][1] == col)) {
                DFS(j, stones, vis);
            }
        }        
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size(),group = 0;
        vector<int> visited(n, 0);
        for (int i = 0;i<n;i++)
            if (!visited[i]) 
            {
                group++;
                DFS(i, stones, visited);
            }
        return (stones.size() - group);
    }
};