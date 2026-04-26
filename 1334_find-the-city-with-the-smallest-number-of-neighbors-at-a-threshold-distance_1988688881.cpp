class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // graph[i][j] - distance from city i to city j
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        // adjacency matrix
        for (auto& e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            dist[u][v] = dist[v][u] = wt;
        }
        for (int i = 0; i < n; i++) dist[i][i] = 0;

        // ALL PAIRS FLOYD WARSHALL
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // city i --> j
                    // (i,j) = (i,k) + (k,j)
                    if (dist[i][k] != 1e9 && dist[k][j] != 1e9) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // scan every row (city) for max neighbours within threshold
        int ans = -1, minCount = n;
        for (int city = 0; city < n; city++) {
            int count = 0;
            for (int nbr = 0; nbr < n; nbr++)
                if (dist[city][nbr] <= distanceThreshold)
                    count++;

            if (count <= minCount) {
                minCount = count;
                ans = city;
            }
        }
        return ans;
    }
};