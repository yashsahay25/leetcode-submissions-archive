class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> dist(n+1, vector<int> (n+1,1e9));

        for(int i=1;i<=n;i++) dist[i][i]=0;

        for(int i=1;i<n;i++){
            dist[i][i+1]=1;
            dist[i+1][i]=1;
        }

        if(x!=y){
            dist[x][y]=1;
            dist[y][x]=1;
        }

        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dist[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
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