class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adj(n+1);
        for(int i=1;i<n;i++){
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }
        adj[x].push_back(y);
        adj[y].push_back(x);

        vector<vector<int>> dist(n+1, vector<int> (n+1,1e9));

        for(int src=1;src<=n;src++){
            queue<int> q;
            q.push(src);

            dist[src][src]=0;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto& nbr:adj[node]){
                    if(dist[src][node]+1<dist[src][nbr]){
                        dist[src][nbr]=dist[src][node]+1;
                        q.push(nbr);
                    }
                }
            }
        }

        vector<int> result(n,0);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j && dist[i][j]!=1e9){
                    // result of k at k-1 index
                    int k = dist[i][j] - 1;
                    result[k]++;
                }
            }
        }
        return result;
    }
};