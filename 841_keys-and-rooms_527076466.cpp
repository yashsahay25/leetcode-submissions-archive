class Solution {
public:
    void dfs(vector<vector<int>> &graph, int src, vector<bool> &vis){
        vis[src] = true;
        for(int i = 0; i < graph[src].size(); i++){
            if(!vis[graph[src][i]]){
                dfs(graph, graph[src][i], vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int i, n=rooms.size();
        vector<bool> vis(n, false);
        dfs(rooms, 0, vis);
        for(i = 0; i < n; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};