class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> price(n, 1e9);
        queue<pair<int, int>> q; // <node, cost>

        q.push({src, 0});
        price[src] = 0;

        int stops = 0;
        while (!q.empty()) {
            // if k stops covered, no need to BFS further
            if (stops > k) break;

            // traverse all elements of the level
            int size = q.size();
            while (size--) {
                // take out first element of this level
                auto [node, cost] = q.front();
                q.pop();

                for (auto [nbr, wt] : adj[node]) {
                    if (cost + wt < price[nbr]) {
                        price[nbr] = cost + wt;
                        q.push({nbr, price[nbr]});
                    }
                }
            }
            stops++;
        }
        return price[dest] == 1e9 ? -1 : price[dest];
    }
};