class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<vector<int>>& pathList,
             vector<int> currPath, int curr, int dst) {
        // add current node to current path being traversed
        currPath.push_back(curr);

        // if destination reached, add current path to pathList
        if (curr == dst) {
            pathList.push_back(currPath);
            return;
        }

        // go to neighbor
        for (auto& nbr : adj[curr])
            dfs(adj, pathList, currPath, nbr, dst);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<vector<int>> pathList;
        
        vector<int> currPath;
        dfs(graph, pathList, currPath, 0, n - 1);
        
        return pathList;
    }
};