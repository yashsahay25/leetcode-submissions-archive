class Solution {
public:
    bool dfs(int node, vector<int>& visited, vector<int>& path,
             vector<int> adj[]) {
        visited[node] = 1; // mark node as visited
        path[node] = 1;    // also add node to path

        for (auto nbr : adj[node]) {
            // if adjacent node is unvisited, call dfs
            if (!visited[nbr]) {
                if (dfs(nbr, visited, path, adj) == true)
                    return true;
            }
            // if adjacenet node is visted and also in same path
            else if (path[nbr] == 1)
                return true;
        }
        path[node] = 0; // backtrack: remove from path while returning
        return false;   // no cycle found
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // directed edge from b to a in [a,b]
        vector<int> adj[n];
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> visited(n, 0);
        vector<int> path(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, path, adj))
                    return false;
            }
        }
        return true;
    }
};