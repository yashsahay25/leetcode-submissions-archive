class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Bellman Ford algo
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // run it k+1 times (also counting dest as stop)
        for (int i = 0; i <= k; i++) {
            // temp vector to hold distances, initialise with dist
            vector<int> temp(dist);

            for (auto& f : flights) {
                int u = f[0];
                int v = f[1];
                int wt = f[2];

                if (dist[u] != 1e9 && dist[u] + wt < temp[v]) {
                    temp[v] = dist[u] + wt;
                }
            }
            dist = temp; // update distance vector
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};