class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adj){
        // mark node as visited
        visited[node]=true;
        // traverse neighbours one by one. neighbours = adj[node]
        for(int nbr=0;nbr<adj[node].size();nbr++){
            if(nbr==node) continue; // to skip [nbr][nbr]

            // if edge exists & neighbour not visited
            if(adj[node][nbr] && !visited[nbr]){
                dfs(nbr,visited,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n,0); // can take boolean visited array as well
        
        int count=0; // provinces
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,isConnected);
            }
        }
        return count;
    }
};