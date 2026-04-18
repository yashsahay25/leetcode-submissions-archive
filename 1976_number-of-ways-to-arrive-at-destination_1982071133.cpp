typedef pair<long long, int> pli;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // build adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto& r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]}); // undirected graph
        }

        priority_queue<pli, vector<pli>, greater<pli>> pq;
        vector<long long> dist(n, 1e15);
        vector<long long> ways(n, 0);

        // source node
        pq.push({0, 0}); // (distance, node)
        dist[0] = 0;
        ways[0] = 1; // There is atleast 1 way to reach node 0 from 0

        int mod = 1e9 + 7;

        // start Dijkstra's
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            // pruning, avoids TLE
            if (d > dist[node]) continue;

            for (auto& [nbr, wt] : adj[node]) {
                long long newDist = d + wt;

                // new lesser distance found, then update
                if (newDist < dist[nbr]) {
                    dist[nbr] = newDist;
                    ways[nbr] = ways[node];
                    pq.push({dist[nbr], nbr});
                } else if (newDist == dist[nbr]) {
                    // if same distance found, means another path found
                    // so ways[nbr] += ways[node]
                    ways[nbr] = (ways[nbr] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};