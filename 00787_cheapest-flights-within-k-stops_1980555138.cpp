class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> price(n, 1e9);
        queue<pair<int, int>> q; // <node, currCost to reach that node>

        q.push({src, 0});
        price[src] = 0;

        int stops = 0;
        // only k stops allowed
        while (!q.empty() && stops <= k) {
            
            // traverse all elements of the level
            int size = q.size();

            // while loop on size is necessary else we will increase
            // stops/level for every node, which is wrong
            while (size--) {
                // take out each element of this level
                auto [node, currCost] = q.front();
                q.pop();

                for (auto [nbr, wt] : adj[node]) {
                    if (currCost + wt < price[nbr]) {
                        price[nbr] = currCost + wt;
                        q.push({nbr, price[nbr]});
                    }
                    // here we used (currCost + wt) instead of (price[node] + wt)
                    // as price[] isn't final yet. It can be changed via another path.
                    // The queue contains the actual state of the cost/prices
                }
            }
            stops++;
        }
        return price[dest] == 1e9 ? -1 : price[dest];
    }
};