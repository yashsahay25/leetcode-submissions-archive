class Solution {
public:
    void bfs(int start, vector<int>& visited, vector<vector<int>>& adj){
        queue<int> q;
        q.push(start);
        visited[start]=1;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int nbr=0;nbr<adj[node].size();nbr++){
                if(nbr==node) continue;
                if(adj[node][nbr] && !visited[nbr]){
                    visited[nbr]=1;
                    q.push(nbr);
                }
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
                bfs(i,visited,isConnected);
            }
        }
        return count;
    }
};